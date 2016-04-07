// Time-stamp: </wrf/c/nearpt3/compcellsearchorder.cc, Mon, 25 Apr 2005, 17:00:50 EDT, http://wrfranklin.org/>

// Compute the order in which to search the neighboring cells of the cell containing the query
// point.  I.e., sort the cells in one 48-th-ant of 3-space out to a certain distance (dmax-1), and
// write that list to cout.

// Also write an index giving how far to search if the first point was found in this cell.

// If this was compiled to write binary output, the format is  4 unsigned short ints per record
//  c00 c01 c02 k0
//  c10 c11 c12 k1
// ...

// Otherwise this writes ascii to cout, with a comma after each number, so that the output can be
// included in the nearpt3.cc source.


// W. Randolph Franklin,  http://wrfranklin.org/

#include <iostream>
#include <fstream>
#include <boost/multi_array.hpp> 
#include <math.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>

using namespace std;
using boost::array;

// Print an expression's name then its value, possible followed by a comma or endl.  
// Ex: cout << PRINTC(x) << PRINTN(y);

#define PRINT(arg)  #arg "=" << (arg)
#define PRINTC(arg)  #arg "=" << (arg) << ", "
#define PRINTN(arg)  #arg "=" << (arg) << endl

const int dmax = 200;
const int dmax3 = dmax * (dmax+1) * (dmax+2) / 6;

typedef short int Cell3t;
typedef array<Cell3t,3> Cell;


double dsq(const Cell3t x) {
  const double a = static_cast<double> (x);
  return a*a;
}

double distsq(const Cell c) {
  return dsq(c[0])+dsq(c[1])+dsq(c[2]);
}

class cellcomp {
public:
  bool operator() (const Cell c1, const Cell c2) const 
  {
    return distsq(c1) < distsq(c2);
  }
};


int main() {
  vector<Cell> a;
  a.reserve(dmax3);
  a.resize(0);  // paranoia.
  Cell c;
  for(c[0]=0; c[0]<dmax; c[0]++)
    for(c[1]=c[0]; c[1]<dmax; c[1]++)
      for(c[2]=c[1]; c[2]<dmax; c[2]++) {
	a.push_back(c);
      }
  const int n=a.size();
  cerr << PRINTC(dmax) << PRINTC(dmax3) << PRINTN(n);

#ifdef NO
  cerr << "Before sorting:" << endl;
  for (int i=0; i<dmax3; i++) 
    cerr << "a[" << i << "]=" << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << endl;
#endif
  sort(a.begin(), a.begin()+n, cellcomp());

  vector<int> stop(n);

  int istop=0;
  for (int i=0; i<dmax3; i++) {
    const Cell &c1 = a[i];
    Cell c2(c1);
    c2[0] += 2;
    c2[1] += 2;
    c2[2] += 2;
    const double d2 = distsq(c2);
    // If the first fixed point is found in cell c, we must search all cells as close or closer than
    // d2 to be sure of finding any closer point.
    for (;istop<n;istop++) 
      if (distsq(a[istop]) > d2) break;
    //    cerr << PRINTC(distsq(a[istop])) << PRINTC(d2) << PRINTN(distsq(a[istop]) - d2);
    stop[i] = istop;
  }
#ifdef DEBUGTHIS
  cerr << "After sorting:" << endl;
  for (int i=0; i<dmax3; i++) 
    cerr << "a[" << i << "]=" << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << endl;
#endif
  for (int i=0; i<n; i++) {
#ifdef WRITEBIN
    cout.write(reinterpret_cast<char*>(&a[i]),6);
    cout.write(reinterpret_cast<char*>(&stop[i]),2);
#else
    cout  << a[i][0] << ',' << a[i][1] << ',' << a[i][2] << ',' << stop[i] << ',' << endl;
#endif
  }
}


