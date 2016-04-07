#include <iostream>

using namespace std;

int disc[8], final[8];
int N, K;
int peg[5][8];
int top[5];

bool same()
{
	for (int i = 0; i < N; ++i) {
		if (disc[i] != final[i]) {
			return false;
		}
	}
	return true;
}

void move(int from, int to)
{
	disc[peg[from][top[from]]] = to;
	peg[to][++top[to]] = peg[from][top[from]--];
}

bool legal(int record)
{
	int from = record / K;
	int to = record % K;
	if (from == to || top[from] < 0) {
		return false;
	}
	if (top[to] >= 0 && peg[from][top[from]] > peg[to][top[to]]) {
		return false;
	}
	return true;
}

bool undo(int record[7], int num) {
	if (num == 0) {
		return false;
	}
	int record1 = record[num];
	int record2 = record[num-1];
	return (record1 / K) == (record2 % K) && (record1 % K) == (record2 / K);
}

//disc number 0 to N-1, peg number 0 to K-1
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> disc[i];
		--disc[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> final[i];
		--final[i];
	}
	for (int i = 0; i < K; ++i) {
		top[i] = -1;
	}
	for (int i = N-1; i >= 0; --i) {
		peg[disc[i]][++top[disc[i]]] = i;
	}
	int numMoves = 0, minNumMoves = 7;
	int movesRec[7], minMovesRec[7];
	int end = K * K;
	for (int i = 0; i < 7; ++i) {
		movesRec[i] = 0;
	}
	while(true) {
		while((movesRec[numMoves] < end && !legal(movesRec[numMoves])) || undo(movesRec, numMoves)) {
			++movesRec[numMoves];
		}
		if (movesRec[numMoves] == end) {
			movesRec[numMoves--] = 0;
			if (numMoves < 0) {
				break;
			}
			move(movesRec[numMoves] % K, movesRec[numMoves] / K);
			++movesRec[numMoves];
			continue;
		}
		move(movesRec[numMoves] / K, movesRec[numMoves] % K);	
		if (same()) {
			minNumMoves = numMoves + 1;
			for (int i = 0; i < minNumMoves; ++i) {
				minMovesRec[i] = movesRec[i]; 
			}
		}
		if (numMoves >= minNumMoves - 1) {
			move(movesRec[numMoves] % K, movesRec[numMoves] / K);
			++movesRec[numMoves];
		} else {
			++numMoves;
		}
	}
	cout << minNumMoves << endl;
	for (int i = 0; i < minNumMoves; ++i) {
		cout << minMovesRec[i] / K + 1 << ' ';
		cout << minMovesRec[i] % K + 1 << endl;
	} 
}
