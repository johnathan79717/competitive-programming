// Time-stamp: </wrf/c/nearpt3/asc2binpts.cc, Wed, 11 May 2005, 21:58:30 EDT, http://wrfranklin.org/>

// Read file points, an ascii file of 3D floating points, assumed to be in the range [0,1].  Write
// file binpts in binary, 3 unsigned short ints per point, scaled to be in [0,65535].

// files over 2GB are ok.

// W. Randolph Franklin
// nearpt3 AT wrfranklin.org (Plaintext preferred; attachments deprecated)
// http://wrfranklin.org

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


typedef array<unsigned short int,3> Pt_T;
Pt_T p;
const int sp = sizeof(p);

float fp[3];

unsigned short int conv(const float f) {
  if (f<0. || f > 1.) cerr << "Out of range " << PRINTN(f);
  int i = f * 65535;
  if (i<0) i=0;
  if (i>65535) i=65535;
  return static_cast<unsigned short int>(i);
}

int main() {
  int np=0;
  FILE *sin;
  sin = fopen64("points","r");
  cerr << "Reading points: ";
  if (!sin) {perror("fopen failed");exit(1);}
  ofstream fstream("binpts",ios::binary);   // ios::binary unnecessary in linux.
  if (!fstream) { 
    cout << "ERROR: can't open file binpts" << endl;
    exit(1);
  }
  for (;;) {
    int ret=fscanf(sin,"%f %f %f",&fp[0], &fp[1], &fp[2]);
    if (ret<=0) break;
    if (0==(np++%1000000)) { cerr << np << ' '; }
    for (int i=0; i<3; i++) p[i] = conv(fp[i]);
    fstream.write(reinterpret_cast<char*>(&p),sp);
  }
}



