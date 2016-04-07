#include <iostream>

using namespace std;

#define MAX_N 10005

int N;
string s;
string::iterator it;

int ans[MAX_N];
int arr[MAX_N];
int tmp[MAX_N];

void merge(int *a1, int n1, int *a2, int n2) {
  int i1 = 0, i2 = 0, i = 0;
  while(i1 < n1 && i2 < n2) {
    if(*(it++) == '1')
      tmp[i++] = a1[i1++];
    else
      tmp[i++] = a2[i2++];
  }
  while(i1 < n1)
    tmp[i++] = a1[i1++];
  for(int j = 0; j < i; j++)
    a1[j] = tmp[j];
}

void merge_sort(int *a, int n) {
  if(n <= 1)
    return;
  int mid = n / 2;
  merge_sort(a, mid);
  merge_sort(a + mid, n - mid);
  merge(a, mid, a + mid, n - mid);
}

int solve() {
  for(int i = 0; i < N; i++)
    arr[i] = i;
  merge_sort(arr, N);
  for(int i = 0; i < N; i++)
    ans[arr[i]] = i + 1;
  int result = 1;
  for(int i = 0; i < N; i++)
    result = (31 * result + ans[i]) % 1000003;
  return result;
}

int main() {
  int T, cas=1;
  cin >> T;
  while(T--) {
    cin >> N >> s;
    it = s.begin();
    cout << "Case #" << cas++ << ": " << solve() << endl;
  }
}