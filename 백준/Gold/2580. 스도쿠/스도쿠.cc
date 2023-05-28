#include <bits/stdc++.h>
using namespace std;

#define N 9
#define I idx/N
#define J idx%N

int board[N][N];
int isusedX[N];
int isusedY[N];
int isusedM[N];

void solve(int idx) {
	if (idx >= N*N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << board[i][j] << ' ';
			}cout << '\n';
		}
		exit(0) ;
	}

	if (board[I][J]) solve(idx+1);
	else {
		int m = (J/3) + (I/3)*3;
		for (int n = 1; n <= N; n++) {
			if (isusedX[I] & (1 << n) || isusedY[J] & (1 << n) || isusedM[m] & (1 << n)) continue;
			isusedX[I] += (1 << n);
			isusedY[J] += (1 << n);
			isusedM[m] += (1 << n);
			board[I][J] = n;
			solve(idx+1);
			board[I][J] = 0;
			isusedX[I] -= (1 << n);
			isusedY[J] -= (1 << n);
			isusedM[m] -= (1 << n);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				int m = (j/3) + (i/3)*3;
				isusedX[i] += (1 << (board[i][j]));
				isusedY[j] += (1 << (board[i][j]));
				isusedM[m] += (1 << (board[i][j]));
			}
		}
	}
	solve(0);
}