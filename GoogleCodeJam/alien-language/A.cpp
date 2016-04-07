#include <fstream>
#include <cstring>

using namespace std;

bool match(char *word, bool pattern[15][26])
{
	int L = strlen(word);
	for (int l = 0; l < L; ++l) {
		if(!pattern[l][word[l]-'a']) 
			return false;
	}
	return true;
}

int main(int argc, char* argv[]) 
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int L, D, N;
    fin >> L >> D >> N;
    char dict[5000][20];
    for (int d = 0; d < D; ++d) {
        fin >> dict[d];
    }
    char line[15000];
	bool pattern[15][26];
    for (int n = 1; n <= N; ++n) {
        int count = 0;
        fin >> line;
		bool group;
		int l = 0;
		for (int l = 0; l < 15; ++l) {
			for (int c = 0; c < 26; ++c) {
				pattern[l][c] = false;
			}
		}
		for (int i = 0; line[i] != 0; ++i) {
			switch(line[i]) {
				case '(': 	group = true; break;
				case ')': 	group = false; ++l; break;
				default : 	pattern[l][line[i]-'a'] = true;
						  	if(!group) ++l;
							break;
			}
		}
        for (int d = 0; d < D; ++d) {
			if(match(dict[d], pattern))
				++count;
        }
        fout << "Case #" << n << ": " << count << endl;
    }
}

