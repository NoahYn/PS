#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

char board[6][6];
bool isused[6][6];
bool mask[25];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	for (int i = 0; i < 5; i++)
	 	for (int j = 0; j < 5; j++) 
			cin >> board[i][j];

	fill(mask+18, mask+25, 1);
	do {
		int s= 0, y= 0, idx = 0; // dasom, doyeon first7공주위치
		for (int i = 0; i < 25; i++) {
			if (mask[i] == 1) { // 7 princess
				idx = i;
				if (board[i/5][i%5] == 'S') s++;
				else {
					y++;
					if (y > 3) break;
				}
			}
		}
		if (y > 3) continue; // y가 더 많음

		queue<pair<int, int>> q;
		q.push({idx/5,idx%5}); // 7공주 위치
		isused[idx/5][idx%5] = true;
		int cnt = 0;
		while (!q.empty()) { // 7공주 인접체크
			pair<int,int> p = q.front(); q.pop(); cnt++;
			for (int dir = 0; dir < 4; dir++) {
				int nx = p.X + dx[dir];
				int ny = p.Y + dy[dir];
				if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
				if (mask[nx*5+ny] == 0) continue;
				if (isused[nx][ny] == true) continue;
				isused[nx][ny] = true;
				q.push({nx,ny});
			}
		}
		if (cnt >= 7)  {
			ans++;
		}
		for (int i = 0; i < 5; i++) fill(isused[i], isused[i]+5, 0);
	} while(next_permutation(mask, mask+25));
	cout << ans;
}