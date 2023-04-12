#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, k, x, y, jump;
string board[1000];
int dist[1000][1000][11]; 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	if (n == 1 && m == 1) {
		cout << 1; return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	queue<tuple<int,int,int>> q;
	q.push({0,0,0});
	for (int i = 0; i <= k; i++) {
		dist[0][0][i] = 1;
	}
	while (!q.empty()) {
		tie(x, y, jump) = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (nx == n-1 && ny == m-1) {
				cout << dist[x][y][jump] + 1;
				return 0;	
			}
			if (board[nx][ny] == '0' && dist[nx][ny][jump] == 0) {
				q.push({nx,ny,jump});
				dist[nx][ny][jump] = dist[x][y][jump] +1;
			}
			if (jump < k && board[nx][ny] == '1' && dist[nx][ny][jump+1] == 0) { 
				q.push({nx,ny,jump+1});
				dist[nx][ny][jump+1] = dist[x][y][jump] + 1;
			}
		}
	}
	cout << -1;
}