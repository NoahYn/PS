#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[51][51];
int vis[51][51];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, n, m, k, x,y;
	int cnt;
	cin >> T;
	while (T--) {
		cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> y >> x;
			board[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0 || vis[i][j] == 1) continue;
				queue<pair<int, int>> q;
				q.push({i,j});
				vis[i][j] = 1;
				if (k > cnt)
					++cnt;
				while (!q.empty()) {
					pair<int, int> p = q.front(); q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = p.X + dx[dir];
						int ny = p.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] == 0 || vis[nx][ny] == 1)continue;
						vis[nx][ny] = 1;
						q.push({nx,ny});
					}
				}
			}
		}
		cout << cnt << "\n";
		for (int i = 0; i< n; i++) {
			fill(vis[i], vis[i]+m, 0);
			fill(board[i], board[i]+m, 0);
		}
	}
}