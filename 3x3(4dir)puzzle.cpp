/*
name : Sungmin Yoon
student ID : 2021202033
*/

#include <bits/stdc++.h>
using namespace std;

#define N 9
#define DIR 4
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int pieces[N][DIR]; // input pieces
int perm[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
array<pair<int, int>, N> board; // one answer : first is piece, second is direction
vector<array<pair<int,int>, N>> ans; // set of answer

bool ismatched(int a, int b) {
	return (((a-1)/2 == (b-1)/2) && a%2 != b%2);
} // 1-2, 3-4, 5-6, 7-8

void Backtracking(int idx) { 
	/*
	input :
		idx - index of board to put next(1~8). if idx is 9, one answer is solved
	*/
	if (idx >= N) { // all the pieces are matched 
		ans.push_back(board);
		return ;
	}

	int left = idx-1; // left piece
	int up = idx-3; // upper piece

	if (idx == 4) {
		int a =0;
	}
	for (int rot = 0; rot < DIR; rot++) {
		if ((left%3) < 2) { // idx is not on most left position
			int rol = pieces[board[left].first][(board[left].second + RIGHT)%4]; // right part of left piece
			int lor = pieces[perm[idx]][(rot+LEFT)%4]; // left part of right piece
			if (!ismatched(rol, lor)) {
				continue; 
			}
		}
		if (up >= 0) {
			int dou = pieces[board[up].first][(board[up].second+DOWN)%4]; // down part of upper piece
			int uod = pieces[perm[idx]][(rot+UP)%4]; // upper part of down piece
			if (!ismatched(uod, dou)) {
				continue;
			}			
		}
		board[idx] = {perm[idx], rot};
		Backtracking(idx+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < DIR; j++) {
			cin >> pieces[i][j];
		}
	}

	do {
		for (int rot = 0; rot < DIR; rot++) {
			board[0] = {perm[0], rot}; // put first piece in every direction
			Backtracking(1); // go secind piece and so on
		}
	} while(next_permutation(perm, perm+N));

	cout << ans.size() << '\n';
	for (auto &k : ans) {
		for (int i = 0; i < N; i++) {
			cout << k[i].first + 1 << "(" << k[i].second << ") ";
		} cout << '\n';
	}
}

