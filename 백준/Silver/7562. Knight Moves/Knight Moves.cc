#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int n, m;
int dist[302][302];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m;
	pair<int, int> p;
	while (m--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			fill(dist[i], dist[i]+n, -1);
		}
		queue<pair<int, int>> q;
		cin >> p.X >> p.Y;
		if (p.X < 0 || p.X >= n || p.Y < 0 || p.Y >= n) {
			cout << 0 << "\n";
			continue;
		}
		dist[p.X][p.Y] = 1;
		q.push(p);
		cin >> p.X >> p.Y;
		if (p.X < 0 || p.X >= n || p.Y < 0 || p.Y >= n) {
			cout << 0 << "\n";
			continue;
		}
		if (dist[p.X][p.Y] == 1) {
			cout << 0 << "\n";
			continue;
		}
		dist[p.X][p.Y] = 0;
		while (!q.empty()) {
			p = q.front(); q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = p.X + dx[dir];
				int ny = p.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (dist[nx][ny] > 0) continue;
				if (dist[nx][ny] == 0) {
					cout << dist[p.X][p.Y] << "\n";
					while (!q.empty())
						q.pop();
					break;
				}
				q.push({nx,ny});
				dist[nx][ny] = dist[p.X][p.Y]+1;
			}
		}
	}
}