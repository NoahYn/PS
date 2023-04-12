#include <bits/stdc++.h>
using namespace std;
int n,m;
string board[102];
int dist[102][102];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		fill(dist[i], dist[i] + m, -1);
	}
	queue<pair<int, int>> q;
	q.push({0, 0});
	dist[0][0] = 0;
	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int y = p.first + dy[dir];
			int x = p.second + dx[dir];
			if (y < 0 || x < 0 || y > n-1 || x > m-1) continue;
			if (dist[y][x] >= 0 || board[y][x] == '0') continue;
			q.push({y,x});
			dist[y][x] = dist[p.first][p.second] + 1;
		}
	}
	cout << dist[n-1][m-1] + 1;
}