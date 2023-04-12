#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
string board[101];
int vis[101][101];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;
			queue<pair<int,int>> q;
			q.push({i,j});
			vis[i][j] = 1;
			while (!q.empty()) {
				pair<int, int> p = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = p.X + dx[dir];
					int ny = p.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] != board[p.X][p.Y]) continue;
					q.push({nx,ny});
					vis[nx][ny] = 1; 
				}
			}
			ans++;
		}
	}
	cout << ans << " ";

	for (int i = 0; i < n; i++) {
		replace(board[i].begin(), board[i].end(), 'R', 'G');
		fill(vis[i], vis[i]+n, 0);
	}
	ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j]) continue;
			queue<pair<int,int>> q;
			q.push({i,j});
			vis[i][j] = 1;
			while (!q.empty()) {
				pair<int, int> p = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = p.X + dx[dir];
					int ny = p.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] != board[p.X][p.Y]) continue;
					q.push({nx,ny});
					vis[nx][ny] = 1; 
				}
			}
			ans++;
		}
	}
	cout << ans;
}