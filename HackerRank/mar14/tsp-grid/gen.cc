#include <fstream>
using namespace std;
char file[3];
int main() {
  for(int m = 2; m <= 10; m++) {
    file[0] = '0' + m;
    for(int n = 2; n <= 10; n++) {
      if(m%2 && n%2) continue;
      file[1] = '0' + n;
      ofstream out(file);
      out << m << ' ' << n;
      for(int k = 0; k < m*(n-1)+(m-1)*n; k++)
        out << " 1";
      out << endl;
    }
  }
}