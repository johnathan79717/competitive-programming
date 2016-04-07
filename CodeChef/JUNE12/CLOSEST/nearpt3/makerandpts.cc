// Time-stamp: </wrf/c/nearpt3/makerandpts.cc, Wed, 11 May 2005, 21:47:38 EDT, http://wrfranklin.org/>

// Write random points to cout until you stop it.   Write different random points each time.
// Write numbers in fixed width, for ease in processing large files.

// Wm Randolph Franklin
// wrf@ecse.rpi.edu (Plaintext preferred; attachments deprecated)
// http://www.ecse.rpi.edu/Homepages/wrf/

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// http://www.boost.org/libs/format/doc/format.html
#include <boost/format.hpp>
using boost::format;
using boost::io::group;

using namespace std;

int main() {
  const double RM = static_cast<double>(RAND_MAX);

 time_t t = time(0);
 srandom(t);

 format fmt("%9.6f %9.6f %9.6f\n");


  for (;;) {
    long int x = random();
    long int y = random();
    long int z = random();
    double xx = static_cast<double>(x)/RM;
    double yy = static_cast<double>(y)/RM;
    double zz = static_cast<double>(z)/RM;
    cout << fmt % xx % yy % zz;
  }
}


