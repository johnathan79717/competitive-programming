// Time-stamp: </wrf/c/nearpt3/nearpt3.cc, Mon,  5 Dec 2005, 23:00:33 EST, http://wrfranklin.org/>

// Nearest point query in E3.

// There are 2 user-callable subroutines:
//  preprocess:   insert fixed points into a uniform grid. 
// query: find the closest fixed point to a query point.

// W. Randolph Franklin
// nearpt3 AT wrfranklin.org (Plaintext preferred; attachments deprecated)
// http://www.ecse.rpi.edu/Homepages/wrf/


#include <algorithm>
#include <boost/multi_array.hpp> 
#include <iomanip>
#include <iostream>
#include <fstream>
#include <math.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>


using namespace std;
using boost::array;

// Print an expression's name then its value, possibly followed by a comma or endl.  
// Ex: cout << PRINTC(x) << PRINTN(y);

#define PRINT(arg)  #arg "=" << (arg)
#define PRINTC(arg)  #arg "=" << (arg) << ", "
#define PRINTN(arg)  #arg "=" << (arg) << endl


// clamp_USI     Convert to an unsigned short int while clamping

template <typename T>
unsigned short int clamp_USI(T a) {
  const unsigned short int m(numeric_limits<unsigned short int>::max());
  const T mm(static_cast<T>(m));
  return  
    static_cast<unsigned short int>(a > mm ? mm : (a > 0 ? static_cast<unsigned short int>(a) : 0));
}


namespace nearpt3 {   // start of namespace nearpt3

  double ng_factor = 1.6;   //  ng = ng_factor* cbrt(nfixpts)

#ifdef STATS
    static const int Cells_Checked_to_Closest_Point_Per_Query_Size(5000);
#endif

  double square(const double x) {
    return x*x;
  }

  template <typename Coord_T>
  double Distance2(const array<Coord_T, 3> a, const array<Coord_T, 3> b) {
    return (square((a[0]-b[0]))+square((a[1]-b[1]))+square((a[2]-b[2])));
  }


  // cellsearchorder:
  // First 3 elements of each row:  the order in which to search (one 48th-ant of the) cells adjacent to the current cell.
  // 4th element:   where, in cellsearchorder, to stop searching after the first point is found.
  const static int  cellsearchorder[][4] = {
#include "cellsearchorder"
  };
  // Number of cells in cellsearchorder (before expanding symmetries).
  const static int ncellsearchorder = 
    sizeof(nearpt3::cellsearchorder) / sizeof(nearpt3::cellsearchorder[0][0])/4;

  typedef short int Cell3_Index_T;           // Type of a cell index
  class Cell3 {     //   Cell ID, expressed as a triple.of Cell3_Index_T.
  public:
    array<Cell3_Index_T,3> c;

    Cell3(const Cell3_Index_T x, const Cell3_Index_T y, const Cell3_Index_T z) {
      c[0] = x; c[1] = y; c[2] = z; }

    Cell3(const Cell3 &a) { c[0] = a[0]; c[1] = a[1]; c[2] = a[2]; }

    Cell3() { c[0] = -1; c[1] = -1; c[2] = -1; }

    Cell3_Index_T & operator[] (const int i)  {  return c[i];  }

    const Cell3_Index_T & operator[] (const int i) const {  return c[i];  }

    const Cell3 operator+(const Cell3 &d) const {
      Cell3 r;
      r[0] = c[0]+d[0];
      r[1] = c[1]+d[1];
      r[2] = c[2]+d[2];
      return r;
    }

    const Cell3 operator*(const int *d) const {
      Cell3 r;
      r[0] = c[0]*d[0];
      r[1] = c[1]*d[1];
      r[2] = c[2]*d[2];
      return r;
    }

    bool operator==(const Cell3 &d)  const {
      return c[0]==d[0] && c[1]==d[1] && c[2]==d[2];
    }

    //    const Cell3 operator*(const int *) const;
  };

  //  ostream& operator<<(ostream&, const Cell3& );




  void write(ostream &o, const Cell3& c) {
    o << '(' << c[0] << ',' << c[1] << ',' << c[2] << ") ";
  }


  // Grid_T is the main data structure to store the preprocessed points in a grid, plus auxiliary info.

  template<typename Coord_T>
  class Grid_T{
  public:                  // start of Grid_T
    int ng;                // Number of grid cells on a side
    int ng3;               // ng*ng*ng
    double r_cell;        // cellindex = coord*r_cell+d_cell;
    double d_cell[3]; 
    int nfixpts;           // number of fixed points.
    const array<Coord_T,3>  * pts;   // pointer to user-supplied points.
    vector<int> cells;  // The indices (in pts) of the points in each cell, for all the cells.
    vector<int> base;   // Dope vector pointing to the start of each cell, in cells.  The i-th point of 
    // the j-th cell is cells[base[j]+i].   Also, initially this is used to count the number of points per cell.

#ifdef STATS
    int   Max_Cells_Checked_to_1st_Point_Per_Query;
    float Average_Cells_Checked_to_1st_Point_Per_Query;
    int Tot_Cells_Checked_to_1st_Point_Per_Query;
    vector<int> Cells_Checked_to_1st_Point_Per_Query;
    vector<int> Cells_Checked_to_Closest_Point_Per_Query;
    vector<int> Points_Checked_Per_Query;
#endif

    // check and clip cannot be members of Cell3 since they need access to ng.

    // Check if this is a legal cell.
    bool check(const Cell3 a) const;

    // clip is needed because roundoff errors may cause a number to be slightly outside the legal range. 
    void clip(Cell3 &a);

    template<typename T> 
    void Check_Range(const string msg, const int i, const T x, const T lo, const T hi);

    void Check_Range(const string msg, const int i, const Cell3 x);

    // cellid_to_int: Convert Cell ID from 3 short ints to one int.  The following static_casts are
    // to prevent an overflow during the multiplication in case ng is short int.  If the arg is out
    // of range, as might happen for a query, then return -1.

    int cellid_to_int(const Cell3 a) const;


    // Compute_Cell_Containing_Point: Return the cell number containing point p.  Note the p is a
    // array<Coord_T, 3>, not an id of a point.  This is necessary since
    // Compute_Cell_Containing_Point is used for both fixed and query points.

    const Cell3 Compute_Cell_Containing_Point(const array<Coord_T,3> p);

    // N_Points_in_This_Cell: Return the number of fixed points in cell ic.  If the arg is out of
    // range, as will happen for a really distant query, then return 0.

    int N_Points_in_This_Cell(const int ic);

    // querythiscell: Query cell thiscell with query point querypt.  Return closestpt, the index of
    // the closest fixed point in the cell, and dist2, the square of the distance.  Return -1 if
    // there are no points in this cell.

    void querythiscell(const Cell3 thiscell, const array<Coord_T, 3> querypt, 
		       int &closestpt, double &dist2);

    // Query_Fast_Case: Return the id of the closest fixed point to query point iq, for the fast case
    // of the query point cell containing at least one fixed point.

    // If that cell has no fixed point, then return -1.

    int Query_Fast_Case(const array<Coord_T, 3> q,   const Cell3 querycell);

  };   // End of Grid_T


#ifdef STATS
  int N_Cells_Checked_to_1st_Point_This_Query;
  int N_Points_Checked_This_Query;
#endif
  int N_Cells_Checked_to_Closest_Point_This_Query;

  // Check if this is a legal cell.
  template<typename Coord_T> bool  nearpt3::Grid_T<Coord_T>::check(const Cell3 a) const {
    if (a[0] < 0 || a[0] >= ng ) return false;
    if (a[1] < 0 || a[1] >= ng ) return false;
    if (a[2] < 0 || a[2] >= ng ) return false;
    return true;
  }

  // clip is needed because roundoff errors may cause a number to be slightly outside the legal range. 
  template<typename Coord_T> void nearpt3::Grid_T<Coord_T>:: clip(Cell3 &a) {

    //    a[0] = min(ng-1, max(0, a[0]));

    if (a[0] < 0) a[0] = 0;
    if (a[0] >= ng) a[0] = ng-1;
    if (a[1] < 0) a[1] = 0;
    if (a[1] >= ng) a[1] = ng-1;
    if (a[2] < 0) a[2] = 0;
    if (a[2] >= ng) a[2] = ng-1;
  }

  template<typename T> 
  void Check_Range(const string msg, const int i, const T x, const T lo, const T hi) {
    if (x<lo || x>hi) {
      cout << "ERROR, number out of range: " << msg << ' ' << PRINTC(i) << PRINTC(x) << PRINTC(lo) << PRINTN(hi);
      throw "Number out of range";
    }
  }

  template<typename Coord_T> void nearpt3::Grid_T<Coord_T> :: 
  Check_Range(const string msg, const int i, const Cell3 x) {
    if (!check(x)) {
      cout << "ERROR, cell3 out of the range [0,ng): " << msg << ' ' << PRINTC(i) << PRINTC(x[0]) << PRINTC(x[1]) << PRINTC(x[2]) << PRINTN(ng);
      throw "Cell3 out of range";
    }
  }


  // cellid_to_int: Convert Cell ID from 3 short ints to one int.  The following static_casts are
  // to prevent an overflow during the multiplication in case ng is short int.  If the arg is out
  // of range, as might happen for a query, then return -1.

  template<typename Coord_T> int nearpt3::Grid_T<Coord_T>::
  cellid_to_int(const Cell3 a) const { 
    if (a[0]<0 || a[0] >=ng || a[1]<0 || a[1] >=ng || a[2]<0 || a[2] >=ng) return -1;
    return  (static_cast<int> (a[0])*ng + static_cast<int>(a[1]))*ng + a[2]; 
  }



  // Compute_Cell_Containing_Point: Return the cell number containing point p.  Note the p is a
  // array<Coord_T, 3>, not an id of a point.  This is necessary since
  // Compute_Cell_Containing_Point is used for both fixed and query points.

  template<typename Coord_T> const nearpt3::Cell3 nearpt3::Grid_T<Coord_T>::
  Compute_Cell_Containing_Point(const array<Coord_T,3> p) {
    const short int ix = static_cast<short int>(static_cast<double>(p[0])*r_cell+d_cell[0]);   // This must truncate not round.
    const short int iy = static_cast<short int>(static_cast<double>(p[1])*r_cell+d_cell[1]);
    const short int iz = static_cast<short int>(static_cast<double>(p[2])*r_cell+d_cell[2]);
    Cell3 c(ix, iy, iz);
    return c;
  }

  // N_Points_in_This_Cell: Return the number of fixed points in cell ic.  If the arg is out of
  // range, as will happen for a really distant query, then return 0.

  template<typename Coord_T> int nearpt3::Grid_T<Coord_T> :: 
  N_Points_in_This_Cell(const int ic) {
    if (ic<0) return 0;
    return base[ic+1] - base[ic];
  }


  // querythiscell: Query cell thiscell with query point querypt.  Return closestpt, the index of
  // the closest fixed point in the cell, and dist2, the square of the distance.  Return -1 if
  // there are no points in this cell.

  template<typename Coord_T> void nearpt3::Grid_T<Coord_T> :: 
  querythiscell(const Cell3 thiscell, const array<Coord_T, 3> querypt, 
		int &closestpt, double &dist2) {
    closestpt = -1;
    dist2 = numeric_limits<double>::max();
    int ic = cellid_to_int(thiscell);
    const int ppc = N_Points_in_This_Cell(ic);
    for (int i=0; i<ppc; i++) {
      const int ip = base[ic]+i;
      const double d2 = Distance2(pts[cells[ip]], querypt);
      if (d2 < dist2 || (d2==dist2 && cells[ip]<closestpt)) {
	dist2 = d2;
	closestpt = cells[ip];
      }
    }
    return;
  }



  // Query_Fast_Case: Return the index of the closest fixed point to query point iq, for the fast case
  // of the query point cell containing at least one fixed point.

  // If that cell has no fixed point, then return -1.

  template<typename Coord_T> int nearpt3::Grid_T<Coord_T> :: 
  Query_Fast_Case(const array<Coord_T, 3> q,   const Cell3 querycell) 
  {               //  Query_Fast_Case
    const int queryint(cellid_to_int(querycell));
    const int npitc(N_Points_in_This_Cell(queryint));
    if (npitc<=0) return -1;   // Are there any points in this cell?
    // Find the closest point in this cell.
    int closestpt = -1;
    double dist2 = numeric_limits<double>::max();
    for (int i=base[queryint]; i<base[queryint+1]; i++) {
      const double d2 = Distance2(pts[cells[i]], q);
      if (d2 < dist2 || (d2==dist2 && cells[i]<closestpt)) {
	dist2 = d2;
	closestpt = cells[i];
      }
    }

    const double distf = sqrt(dist2) * 1.00001; // fudge factor for roundoff error

    //    cerr /* << PRINTC(q) */ << PRINTC(querycell[0])<< PRINTC(querycell[1])<< PRINTC(querycell[2]) << PRINTN(dist2);

    array<Coord_T, 3> lopt, hipt;
    for (int i=0; i<3; i++) {
      lopt[i] = static_cast<unsigned short int> (clamp_USI(static_cast<double>(q[i]) - distf));
      hipt[i] = static_cast<unsigned short int> (clamp_USI(static_cast<double>(q[i]) + distf + 1.0));
    }

    //    cerr << PRINTC(lopt) << PRINTN(hipt);
    Cell3 locell(Compute_Cell_Containing_Point(lopt));
    Cell3 hicell(Compute_Cell_Containing_Point(hipt));

    clip(locell);   // If the block of cells around the query goes outside the universe,...
    clip(hicell);   // then clip it.

    //    cerr << PRINTC(locell[0]) << PRINTC(locell[1]) << PRINTC(locell[2]) << PRINTC(hicell[0])<< PRINTC(hicell[2])<< PRINTC(hicell[2]);

#ifdef STATS
    N_Cells_Checked_to_1st_Point_This_Query = 1;
    N_Cells_Checked_to_Closest_Point_This_Query = 
      (hicell[0]-locell[0]+1)*(hicell[1]-locell[1]+1)*(hicell[2]-locell[2]+1);
#endif

    if (locell == querycell && hicell == querycell) return closestpt;

    for (Coord_T x=locell[0]; x<=hicell[0]; x++)
      for (Coord_T y=locell[1]; y<=hicell[1]; y++) {
	// Do a whole z-row of cells at once.
	const int i01 = (static_cast<int>(x)*ng + static_cast<int>(y))*ng;
	const int i0 = i01 + locell[2];
	const int i1 = i01 + hicell[2];
	const int hibase=base[i1+1];
	for (int i=base[i0]; i<hibase; i++) {
	  const double d2 = Distance2(pts[cells[i]], q);
	  if (d2 < dist2 || (d2==dist2 && cells[i]<closestpt)) {
	    dist2 = d2;
	    closestpt = cells[i];
	  }
	}
      }
    if (closestpt<0) throw "closestpt<0 at end of Query_Fast_Case but this cell has a point";
    return closestpt;
  }         // Query_Fast_Case



  //   PREPROCESS

  template<typename Coord_T> Grid_T<Coord_T> * 
    Preprocess(const int nfixpts, const array<Coord_T, 3> pts[]) { // preprocess
    Grid_T<Coord_T> *g;
    g = new Grid_T<Coord_T>;
    g->nfixpts = nfixpts;
    int &ng = g->ng;
    ng = static_cast<int> (ng_factor * cbrt(static_cast<double>(nfixpts)));

    ng = min(2000, max(1, ng));
    g->ng3 = ng * ng * ng;
    g->pts = pts;


    // The following check might catch a scrambled cellsearchorder file.
    for (int i=1; i< ncellsearchorder; i++) 
      if (nearpt3::cellsearchorder[i-1][3] > nearpt3::cellsearchorder[i][3]) 
	throw "cellsearchorder is not monotonic";

    array<double,3> lo;
    array<double,3> hi;
    for(int i=0;i<3;i++) {
      lo[i] = numeric_limits<double>::max();
      hi[i] = numeric_limits<double>::min();
    }
    for (int n=0; n<nfixpts; n++) {
      for(int i=0;i<3;i++) {
	lo[i] = min(lo[i], static_cast<double>(pts[n][i]));
	hi[i] = max(hi[i], static_cast<double>(pts[n][i]));
      }
    }
    array<double,3> s;
    array<double,3> d;
    for(int i=0; i<3; i++) {  
      s[i] = 0.99 * ng / (hi[i]-lo[i]);  // allow for a little future roundoff error.
    }
    g->r_cell = min(min(s[0], s[1]), s[2]);

    for(int i=0; i<3; i++) {
      g->d_cell[i] = ((ng-1)-(lo[i]+hi[i])*g->r_cell) * 0.5;
    }


    // Initially use base to count the number of points per cell.
    g->base.resize(g->ng3+1);
    for (int ic=0; ic < g->ng3; ic++) g->base[ic] = 0;

    for (int ip=0; ip<nfixpts; ip++) {       // Count number of points in each cell.
      const nearpt3::Cell3 c(g->Compute_Cell_Containing_Point(pts[ip]));
      g->Check_Range("Cell in pointspercell++", ip, c);
      const int k = g->cellid_to_int(c);
#ifdef DEBUG
      cout << PRINTC(ip) << PRINTC(pts[ip]) << PRINTN(c.c);
#endif
      if (k<0) throw "illegal k in Preprocess";
      g->base[k]++;
      if (g->base[k] > 1000000) {        // Catch an error
	throw "base entry unreasonably large";
      }
    }

    // Now change base[i] from storing the number of points in cell #i to storing the number of
    // points before cell #i.

#ifdef STATS
    const float Average_Points_Per_Cell
      (static_cast<float>(nfixpts)/static_cast<float>(g->ng3)); 
    int Max_Points_Per_Cell(0);
    const int Points_Per_Cell_Size(500);
    vector<int> Points_Per_Cell(Points_Per_Cell_Size, 0);
#endif

    int k = g->base[0];
    g->base[0] = 0;
    for (int ic=1; ic< g->ng3; ic++) {
      int ppc = g->base[ic];
#ifdef STATS
      Max_Points_Per_Cell = max(Max_Points_Per_Cell, ppc);
      Points_Per_Cell[min(ppc,Points_Per_Cell_Size-1)]++;
#endif
      g->base[ic] = g->base[ic-1] + k;
      k = ppc;
    }
    g->base[g->ng3] = g->base[g->ng3-1]+k;
    if (g->base[g->ng3] != nfixpts) {
      cout << "ERROR: Internal inconsistency; wrong " << PRINTN(g->base[g->ng3]);
      throw "Internal inconsistency";
    }

    g->cells.resize(nfixpts);

    // Set the last point of each cell to count how many points have been inserted into that cell so far. 

    for (int i=1; i<= g->ng3; i++) (g->cells)[(g->base)[i]-1] = 0;

    // Insert the points into the grid.

    for (int ip=0; ip<nfixpts; ip++) {    
      const int ic(g->cellid_to_int(g->Compute_Cell_Containing_Point(pts[ip])));
      const int Points_In_This_Cell = g->cells[g->base[ic+1]-1]++;
      g->cells[g->base[ic]+Points_In_This_Cell] = ip;
    }

#ifdef STATS
    cout << PRINTC(nfixpts) << PRINTC(ng) << PRINTC(Average_Points_Per_Cell) 
	 << PRINTN(Max_Points_Per_Cell);
    cout << "Histogram of the number of cells containing K points, 0<=K<" << Points_Per_Cell_Size << ":\n";
    for(int i=0; i< Points_Per_Cell_Size; i++) {
      if (Points_Per_Cell[i]>0) cout << i << ": " << Points_Per_Cell[i] << endl;
    }
    g->Cells_Checked_to_Closest_Point_Per_Query.reserve(Cells_Checked_to_Closest_Point_Per_Query_Size);
    g->Cells_Checked_to_1st_Point_Per_Query.reserve(Cells_Checked_to_Closest_Point_Per_Query_Size);
    g->Points_Checked_Per_Query.reserve(Cells_Checked_to_Closest_Point_Per_Query_Size);
#endif

#ifdef DEBUG
    cout << PRINTN(ng);
    cout << "base: ";
    for (int i=0; i<= g->ng3; i++) cout << i << ':' << g->base[i] << ' ';
    cout << endl << "cells: ";
    for (int i=0; i<nfixpts; i++) cout << i << ':' << g->cells[i] << ' ';
    cout << endl;
#endif

    return g;

  }    // preprocess


  // QUERY:  Return the id of the closest fixed point to query point iq.

  template <typename Coord_T>
  int Query( Grid_T<Coord_T> *g, const array<Coord_T, 3> q) { // Query

#ifdef STATS
    N_Points_Checked_This_Query = 0;
#endif

    nearpt3::Cell3 querycell(g->Compute_Cell_Containing_Point(q));

    // Usually the cell containing the query point has a fixed point.   This is faster to handle.

    int closestpt(g->Query_Fast_Case(q, querycell));
    if (closestpt>=0) {
#ifdef STATS
      g->Cells_Checked_to_Closest_Point_Per_Query[min(Cells_Checked_to_Closest_Point_Per_Query_Size-1, N_Cells_Checked_to_Closest_Point_This_Query)]++;
#endif
      return closestpt;
    }

    double dist(numeric_limits<double>::max());
    int closecell(-1);
    int goodsortnum;
    bool foundit(false);   // Did we find a fixed point yet?
    int nstop(ncellsearchorder);
    N_Cells_Checked_to_Closest_Point_This_Query = 0;
#ifdef STATS
    N_Cells_Checked_to_1st_Point_This_Query = 0;
#endif

    //  Query cells in the order given in cellsearchorder until we find a cell with a point.  Then
    //  keep querying out a little farther in case there is a closer point in another cell.

    // nstop will be changed inside the loop.

    for (int isort=0; isort<nstop; isort++) {  // isort loop
      int thisclosest;
      double thisdist;
      Cell3 s (cellsearchorder[isort][0], cellsearchorder[isort][1], 
	       cellsearchorder[isort][2]);

      //  Derive the 47 other reflected cells from a particular cell being // searched.  That is, from
      //  cell (1,2,3), generate (1,3,2), (1,3,-2), etc

      for (int isign=0; isign<8; isign++) {      // Iterate over all combinations of signs;
	static const int sign3[8][3] = {{1,1,1},{1,1,-1},{1,-1,1},{1,-1,-1},{-1,1,1},
					{-1,1,-1},{-1,-1,1},{-1,-1,-1}};
	if (s[0]==0 && sign3[isign][0]== -1) continue;
	if (s[1]==0 && sign3[isign][1]== -1) continue;
	if (s[2]==0 && sign3[isign][2]== -1) continue;

	const Cell3 s2(s*sign3[isign]);

	for (int iperm=0; iperm<6; iperm++) {   // Iterate over all permutations of coordinates.
	  switch (iperm) {
	  case 1:
	    if (s[1]==s[2]) continue;
	    break;
	  case 2: 
	    if (s[0]==s[1]) continue;
	    break;
	  case 3:
	  case 4:
	    if (s[0]==s[1] && s[0]==s[2]) continue;
	    break;
	  case 5:
	    if (s[0]==s[2]) continue;
	    break;
	  }
	  static const int perm3[6][3] = {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
	  const Cell3 s3(s2[perm3[iperm][0]], s2[perm3[iperm][1]], s2[perm3[iperm][2]]);
	  const Cell3 c2(querycell+s3);
	  if (!g->check(c2)) continue;  // outside the universe?
	  N_Cells_Checked_to_Closest_Point_This_Query++;
	  goodsortnum = isort;
	  g->querythiscell(c2, q, thisclosest, thisdist);
	  if (thisclosest < 0) continue;

	  // If two fixed points are the same distance from the query, then return the one with the
	  // smallest index.  This removes ambiguities, but complicates the code in several places.

	  if (thisdist<dist || (thisdist==dist && thisclosest<closestpt)) {
	    dist = thisdist;
	    closestpt = thisclosest;
	    closecell =  g->cellid_to_int(c2);
	    if (!foundit) {
	      foundit = true;
	      nstop = cellsearchorder[isort][3];
	      if (nstop >= ncellsearchorder) {
		// It took so long to find any cell with a point that cellsearchorder doesn't have
		// enough cells to be sure of finding the closest point.  Fall back to naive
		// exhaustive searching.
		goto L_end_isort;
	      }
	    }
	  }
	}
      }
    }
  L_end_isort: if (closestpt>=0) {
#ifdef STATS
      g->Cells_Checked_to_Closest_Point_Per_Query[min(Cells_Checked_to_Closest_Point_Per_Query_Size-1, N_Cells_Checked_to_Closest_Point_This_Query)]++;
#endif
      return closestpt;   
    }
    // No nearby points, so exhaustively search over all the fixed points.   
    for (int i=0; i< g->nfixpts; i++) {
      double d = Distance2(q, g->pts[i]);
      if (d< dist || (d==dist && i < closestpt)) {
	dist = d;
	closestpt = i;
      }
    }
    return closestpt;  
  }

}  // end of namespace nearpt3



template<typename Coord_T> 
ostream &operator<<(ostream &o, const array<Coord_T,3> &c) {
  o << '(' << c[0] << ',' << c[1] << ',' << c[2] << ')';
  return o;
}

