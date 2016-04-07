// Time-stamp: </wrf/c/nearpt3/main7.cc, Mon,  5 Dec 2005, 23:00:49 EST, http://wrfranklin.org/>

// Sample main program to drive nearpt3, including stats reporting and optional checking.
//  ng_factor must be the first command line arg.   Mod from main6 on 11/19/5.
// Delete some debugging code.

// Reads fixed points from file "fixpts" and queries from file "qpts".  Both contain triples of
// binary unsigned short ints.

// Writes results to file "pairs".  Each result is a query followed by the nearest fixed point,
// both as triples of unsigned short int coords.

// Return query time (per query, in microseconds) as return code.

// W. Randolph Franklin
// nearpt3 AT wrfranklin.org (Plaintext preferred; attachments deprecated)
// http://www.ecse.rpi.edu/Homepages/wrf/

#include "nearpt3.cc"

float clocks_per_sec = -1.0;	// will be set later.
double tottime;

// GET_PROCESS_CPU_TIME Return CPU (user+system) time since start of process.

double Get_Process_CPU_Time ()
{
  struct tms *time_buffer = new tms;
  (void) times (time_buffer);

  if (clocks_per_sec<0.0) clocks_per_sec = sysconf (_SC_CLK_TCK);
  return ((time_buffer->tms_utime + time_buffer->tms_stime) / clocks_per_sec);
}


//  GET_DELTA_TIME Returns time in seconds since last Get_Delta_Time.  Automatically initializes
//  itself on 1st call and returns 0.  Also, return time from process start in its arg.

double Get_Delta_Time (double &new_time)
{
  static double old_time = 0.0;
  double  delta;

  new_time = Get_Process_CPU_Time ();
  delta = new_time - old_time;
  old_time = new_time;
  return delta;
}


// PRINT_TIME Print time since last call, with a message.  Then return the incremental time.

double Print_Time (string msg)
{
  double  incrtime = Get_Delta_Time (tottime);
  //  cout << "\n.....Total CPU Time thru " << msg << " =" << tottime << ", increment="
  //       << incrtime << '\n' << endl;
  return incrtime;
}


int main(const int argc, const char **const argv) {
  typedef unsigned short int Coord_T;
  const int psize = 3*sizeof(Coord_T);
  struct stat buf;

  if (argc!=2) {
    cerr << "ERROR, Exactly one arg, ng_factor, required. " << PRINTN(argc);
    exit(1);
    }
  nearpt3::ng_factor = atof(argv[1]);
  if (nearpt3::ng_factor < 0.01 || nearpt3::ng_factor > 100) {
    cerr << "ERROR, illegal " << PRINTC(nearpt3::ng_factor) << " set to 1." << endl;
    nearpt3::ng_factor = 1.0;
      }
  int ret = stat("fixpts",  &buf);
  if (ret<0) throw "Can't stat fixpts";
  const int fixpts_size = buf.st_size;
  const int nfixpts = fixpts_size / psize;
  array<Coord_T,3> *p;
  p = new  array<Coord_T,3> [nfixpts];
  ifstream fixstream("fixpts",ios::binary);
  if (!fixstream) { 
    throw "ERROR: can't open file fixpts";
  }
  for (int ip=0; ip<nfixpts; ip++) {
    fixstream.read(reinterpret_cast<char*>(&p[ip]), psize);
  }

  const double time_init = Print_Time("Initialization and reading fixed points");

  nearpt3::Grid_T<Coord_T> *g = nearpt3::Preprocess(nfixpts, p);

  const double time_fixed = Print_Time("Processing fixed points");

  ifstream qstream("qpts",ios::binary);
  if (!qstream) { 
    throw "ERROR: can't open file qpts";
  }
  ofstream pstream("pairs",ios::binary);
  if (!pstream) { 
    throw "ERROR: can't open output file pairs";
  }

  int nqpts = 0;

  array<Coord_T,3> q;
  while (qstream.read(reinterpret_cast<char*>(&q),3*sizeof(Coord_T))) {
    nqpts++;
    int closestpt = nearpt3::Query(g, q);
    pstream.write(reinterpret_cast<char*>(&q), psize);
    pstream.write(reinterpret_cast<char*>(&p[closestpt]), psize);

#ifdef EXHAUSTIVECHECK
    // Exhaustive check
    double dist = sqrt(nearpt3::Distance2(q, p[closestpt]));
    int closestpt2 = -1;
    double dist2 = numeric_limits<double>::max();
    for (int i=0; i<nfixpts; i++) {
      double d = nearpt3::Distance2(q, p[i]);
      if (closestpt2<0 || d< dist2 || (d==dist2 && i < closestpt2)) {
	dist2 = d;
	closestpt2 = i;
      }
    }
    if (closestpt2 != closestpt) {
      cout << "ERROR " << PRINTC(closestpt2) << PRINTC(p[closestpt2]) << PRINTN(sqrt(dist2)) << endl;
      cout << PRINTC(q) << PRINTC(closestpt) << PRINTC(p[closestpt]) << PRINTN(dist);
    }
#endif
  }
#ifdef STATS
  int    Max_Cells_Checked_to_Closest_Point_Per_Query(0);
  float    Tot_Cells_Checked_to_Closest_Point_Per_Query(0.0);
  int nqcheck(0);
  for (int i=0; i< nearpt3::Cells_Checked_to_Closest_Point_Per_Query_Size; i++)
    if (g->Cells_Checked_to_Closest_Point_Per_Query[i]>0) {
      Max_Cells_Checked_to_Closest_Point_Per_Query = i;
      Tot_Cells_Checked_to_Closest_Point_Per_Query += 
	i * g->Cells_Checked_to_Closest_Point_Per_Query[i];
      nqcheck += g->Cells_Checked_to_Closest_Point_Per_Query[i];
    }
  if (nqcheck != nqpts) 
    cerr << "Cells_Checked_to_Closest_Point_Per_Query sums to "
	 << PRINTC(nqcheck) << ", but should be " << PRINTN(nqpts);
  float Average_Cells_Checked_to_Closest_Point_Per_Query(Tot_Cells_Checked_to_Closest_Point_Per_Query / nqpts);
  cout << PRINTC(nqpts) << PRINTC(Max_Cells_Checked_to_Closest_Point_Per_Query)
       << PRINTN(Average_Cells_Checked_to_Closest_Point_Per_Query);
  cout << "Histogram of the number of queries that searched K cells\n";
  for(int i=0; i< nearpt3::Cells_Checked_to_Closest_Point_Per_Query_Size; i++) {
    if (g->Cells_Checked_to_Closest_Point_Per_Query[i]>0) 
	cout << i << ": " << g->Cells_Checked_to_Closest_Point_Per_Query[i] << endl;
    }
#endif
  const double time_query = Print_Time("Querying points");
  const double tf = 1e6 * time_fixed / nfixpts;
  const double tq = 1e6 * time_query / nqpts;

  cout.setf(ios::fixed);
    cout << "  nfixpts  ng_fact     ng      t_tot   t_init    t_fixed    t_query    t1f*1e6    t1q*1e6\n";

  cout << setw(9) << nfixpts << " &" <<  setw(7) << nearpt3::ng_factor << " &" << setw(5)
       << g->ng << " & " << setprecision(2) << setw(8) << tottime << " &" 
       << setprecision(3) << setw(7)  << time_init << " & " << setw(8)
       <<  time_fixed << " & " << setw(8) << time_query << " & " 
       << setw(8) << tf << " & " << setw(8) << tq << endl;

  //  sleep(10);   // to give me time to check the memory.
  return static_cast<int>(tq+0.5);
}
