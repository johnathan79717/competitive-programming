#include <fstream>

using namespace std;

int main(int argc, char* argv[]) 
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

	for (int t = 1; t <= T; ++t) {
			
        fout << "Case #" << t << ": " << endl;
    }
}

