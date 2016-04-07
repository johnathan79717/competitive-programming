#include <fstream>
#include <iostream>

using namespace std;

int mergeAndCount(int *A, int a, int *B, int b, int *C)
{
	int i = 0, j = 0, k = 0, count = 0;
	while ( i < a && j < b ) {
		if (A[i] > B[j]) {
			count += (a - i);
			C[k++] = B[j++];
		} else {
			C[k++] = A[i++];
		}
	}
	if (i == a) {
		while (j < b) {
			C[k++] = B[j++];
		}
	} else {
		while (i < a) {
			C[k++] = A[i++];
		}
	}
	return count;
}

int sortAndCount(int *L, int l)
{
	if (l == 1) return 0;
	int *A = L, *B = L + l/2;
	int a = l/2, b = l-l/2;
	int count = 0;
	count += sortAndCount(A, a);
	count += sortAndCount(B, b);
	int *C = new int[l];
	count += mergeAndCount(A, a, B, b, C);
	for (int i = 0; i < l; ++i) {
		L[i] = C[i];
	}
	delete[] C;
	return count;
}

int main(int argc, char* argv[]) 
{
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
	
	int T;
	fin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		fin >> N;
		int L[10001];
		for (int i = 0; i < 10001; ++i) {
			L[i] = 0;
		}
		for (int n = 0; n < N; ++n) {
			int a, b;	
			fin >> a >> b;
			L[a] = b;
		}
		int k = 0;
		for (int i = 0; i < 10001; ++i) {
			if (L[i]) {
				L[k++] = L[i];
			}
		}
        fout << "Case #" << t << ": " << sortAndCount(L, k) << endl;
    }
}

