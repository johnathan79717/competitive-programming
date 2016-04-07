// Time-stamp: </wrf/c/nearpt3/main5.cc, Mon, 16 May 2005, 20:39:00 EDT, http://wrfranklin.org/>

// smallest sample  main program to drive nearpt3.

// Read fixed points as 3 floats from cin, terminated by a number <= -1e30.   That's one number, not 3. 

// Then read query points from cin and for each, find the closest fixed point.

// W. Randolph Franklin
// nearpt3 AT wrfranklin.org (Plaintext preferred; attachments deprecated)
// http://www.ecse.rpi.edu/Homepages/wrf/

#include "nearpt3.cc"

int main() {
  vector<array<float,3> > v;
  array<float,3> p;
  int nfixpts;
  cout << "Enter fixed points, then enter\n-1e30 " << endl;
  for (;;) {
    cin >> p[0];
    if (p[0] <= -0.9e30) break;
    cin >> p[1] >> p[2];
    v.push_back(p);
  }
  nfixpts = v.size();
  cout << "nfixpts= " << nfixpts << endl;
  nearpt3::Grid_T<float> *g = nearpt3::Preprocess(nfixpts, &v[0]);
  for (;;) {
    cout << "Enter a query point: ";
    array<float,3> q;
    cin >> q[0] >> q[1] >> q[2];
    int closestpt = nearpt3::Query(g, q);
    cout << "Query point: (" << q[0] << ", " << q[1] << ", " << q[2] 
	 << ") has closest point #" << closestpt << ": (" << v[closestpt][0] 
	 << ", " << v[closestpt][1] << ", " << v[closestpt][2] << ")" << endl;
  }
  return 0;
}
