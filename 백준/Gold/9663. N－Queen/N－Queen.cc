#include <bits/stdc++.h>
using namespace std;

int board[15][15];
int n;
int cnt = 0;
bool xused[15];
bool xpyused[30];
bool xmyused[30];

void rec(int i) {
	if (i == n) {
		cnt++; return;
	}

	for (int j = 0; j < n; j++) {
		if (xused[j] == true) continue;
		if (xpyused[i+j] == true) continue;
		if (xmyused[i-j+15] == true) continue;
		xused[j] = true;
		xpyused[i+j] = true;
		xmyused[i-j+15] = true;
		rec(i+1);
		xused[j] = false;
		xpyused[i+j] = false;
		xmyused[i-j+15] = false;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rec(0);

	cout << cnt;
}