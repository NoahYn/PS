#include <bits/stdc++.h>
using namespace std;

const int MAX = 1024 * 3 + 2;
char board[MAX][MAX * 2 -1];

void rec(int n, int x, int y) {
	if (n == 3) {
		board[x][y] = '*';
		board[x+1][y-1] = board[x+1][y+1] = '*';
		for (int i = y-2; i <= y+2; ++i) 
			board[x+2][i] = '*';
		return ;
	}
	rec (n/2, x, y);
	rec (n/2, x+n/2, y+n/2);
	rec (n/2, x+n/2, y-n/2);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	rec(n, 0, n-1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n*2-1; ++j) {
			if (board[i][j] == '*')
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}
