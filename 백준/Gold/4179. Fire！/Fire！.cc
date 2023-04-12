#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string maze[1002];
int dist_F[1002][1002]; // 불의 전파 시간
int dist_J[1002][1002]; // 지훈이의 이동 시간
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<pair<int,int>> F;
  queue<pair<int,int>> J;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    fill(dist_F[i], dist_F[i]+m, -1);
    fill(dist_J[i], dist_J[i]+m, -1);    
    cin >> maze[i];  
    for(int j = 0; j < m; j++){
      if(maze[i][j] == 'F'){
        F.push({i,j});
        dist_F[i][j] = 0;        
      }
      else if(maze[i][j] == 'J'){
        J.push({i,j});
        dist_J[i][j] = 0;
      }
    }
  }
  // 불에 대한 BFS
  while(!F.empty()){
    auto cur = F.front(); F.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(dist_F[nx][ny] >= 0 || maze[nx][ny] == '#') continue; 
      dist_F[nx][ny] = dist_F[cur.X][cur.Y]+1;
      F.push({nx,ny});
    }
  }

  // 지훈이에 대한 BFS
  while(!J.empty()){
    auto cur = J.front(); J.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m){ // 범위를 벗어났다는 것은 탈출에 성공했다는 의미. 큐에 거리 순으로 들어가므로 최초에 탈출한 시간을 출력하면 됨.
        cout << dist_J[cur.X][cur.Y]+1; 
        return 0;
      }
      if(dist_J[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
      if(dist_F[nx][ny] != -1 && dist_F[nx][ny] <= dist_J[cur.X][cur.Y]+1) continue; // 불의 전파 시간을 조건에 추가
      dist_J[nx][ny] = dist_J[cur.X][cur.Y]+1;
      J.push({nx,ny});
    }
  }
  cout << "IMPOSSIBLE"; // 여기에 도달했다는 것은 탈출에 실패했음을 의미.
}