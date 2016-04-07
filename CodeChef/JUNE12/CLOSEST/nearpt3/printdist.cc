// Time-stamp: </wrf/c/nearpt3/printdist.cc, Tue, 15 Nov 2005, 22:28:00 EST, http://wrfranklin.org/>

// Read the binary stream cin.  Print the pairs of query and fixed points, and their distance.

// W. Randolph Franklin
// nearpt3 AT wrfranklin.org (Plaintext preferred; attachments deprecated)
// http://wrfranklin.org

#include <iostream>
#include <fstream>
#include <boost/multi_array.hpp> 
#include <iomanip>
#include <math.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/types.h>

using namespace std;

double sqr(const double d) { return d*d;}

main() {
  unsigned short int p[6];
  double pf[6];
  double d;
  //  ifstream pairstream("pairs",ios::binary);
  //  if (!pairstream) { 
  //    cout << "ERROR: can't open file pairs" << endl;
  //    exit(1);
  //  }
  while (cin.read(reinterpret_cast<char*>(&p), sizeof(p))) {
    for (int i=0; i<6; i++) pf[i] = p[i];
    d = sqrt(sqr(pf[0]-pf[3])+sqr(pf[1]-pf[4])+sqr(pf[2]-pf[5]));
    cout << setprecision(15) << '(' << p[0] << ',' << p[1] << ',' << p[2] << ")  (" << p[3] << ',' << p[4] << ',' << p[5] << "): " << d << endl;
  }
}

