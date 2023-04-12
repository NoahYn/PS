#include <bits/stdc++.h>
using namespace std;
int n,m;
int box[1002][1002];
int dist[1002][1002];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push({i,j});
			}
			else if (box[i][j] == 0) {
				dist[i][j] = -1;
			}
		}
	}
	
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int y = p.first + dy[dir];
			int x = p.second + dx[dir];
			if (y < 0 || y >= n || x < 0 || x >= m) continue;
			if (dist[y][x] >= 0)  continue;
			dist[y][x] = dist[p.first][p.second] + 1;
			q.push({y,x});
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
}