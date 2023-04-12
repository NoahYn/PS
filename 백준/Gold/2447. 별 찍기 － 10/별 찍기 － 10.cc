#include <bits/stdc++.h>
using namespace std;
char board[2300][2300];

void rec(int n, int x, int y) {
	if ((x%n) == 1 && (y%n) == 1) {
		board[x][y] = ' ';
	}
	else {
		if ((x/n) % 3 == 1 && (y/n) % 3 == 1)
			board[x][y] = ' ';
		else if (n > 3)
			rec(n/3, x, y);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		fill(board[i], board[i]+n, '*');

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			rec(n, i, j);
		}
	}
	for (int i = 0; i < n; i++)
		cout << board[i] << '\n';
}

/*
3
***
* *
***

n == 9 

1,1 1,4 1,7
4,1 4,4 4,7
7,1 7,4 7,7

3, 3~5
4, 3~5
5, 3~5
x/3 y/3

 012345678
0*********
1* ** ** *
2*********
3***   ***
4* *   * *
5***   ***
6*********
7* ** ** *
8*********

*/