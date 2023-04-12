#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, x, y;
bool jump;
char board[1000][1000];
int dist[1000][1000][2]; 

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}
	queue<tuple<int,int,bool>> q;
	q.push({0,0,0});
	dist[0][0][0] = dist[0][0][1] = 1;
	while (!q.empty()) {
		tie(x, y, jump) = q.front(); 
		if (x == n-1 && y == m-1) { cout << dist[x][y][jump]; return 0;}
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == '0' && dist[nx][ny][jump] == -1) {
				q.push({nx,ny,jump});
				dist[nx][ny][jump] = dist[x][y][jump] +1;
			}
			if (!jump && board[nx][ny] == '1' && dist[nx][ny][1] == -1) { 
				q.push({nx,ny,1});
				dist[nx][ny][1] = dist[x][y][0] + 1;
			}
		}
	}
	cout << -1;
}