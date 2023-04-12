#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, t;
string board[1002];
int dist_f[1002][1002];
int dist_s[1002][1002];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int next = 0;
		cin >> m >> n;
		queue<pair<int, int>> F;
		queue<pair<int, int>> S;
		pair<int, int> p;
		for (int i = 0; i < n; i++) {
			cin >> board[i];
			fill(dist_f[i], dist_f[i]+m, -1);
			fill(dist_s[i], dist_s[i]+m, -1);
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '*') {
					F.push({i,j});
					dist_f[i][j] = 0;	
				}
				else if (board[i][j] == '@') {
					S.push({i,j});
					dist_s[i][j] = 0;
				}
			}
		}
		while (!F.empty()) {
			p = F.front(); F.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = p.X + dx[dir];
				int ny = p.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == '#' || dist_f[nx][ny] >= 0) continue;
				F.push({nx,ny});
				dist_f[nx][ny] = dist_f[p.X][p.Y] +1;
			}
		}
		while (!S.empty()) {
			p = S.front(); S.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = p.X + dx[dir];
				int ny = p.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					cout << dist_s[p.X][p.Y]+1 << "\n";
					while (!S.empty()) S.pop();
					next = 1;
					break;
				}
				if (dist_f[nx][ny] != -1 && dist_f[nx][ny] <= dist_s[p.X][p.Y]+1) continue;
				if (board[nx][ny] == '#' || dist_s[nx][ny] >= 0) continue;
				S.push({nx,ny});
				dist_s[nx][ny] = dist_s[p.X][p.Y] +1;
			}
		}
		if (!next)
			cout << "IMPOSSIBLE\n";
	}
}