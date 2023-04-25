#include <bits/stdc++.h>
using namespace std;

int arr[10][10];
bool mask[100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	fill(mask + k, mask + n*m, true);
	int maxn = -1000000;
	do { // adj check
		int tmp = 0;
		bool adj = false;
		for (int i = 0; i < n*m; i++) {
			if (mask[i]) continue;
			int x = i / m;
			int y = i % m;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (!mask[nx * m + ny]) {
					adj = true;
					break;
				}
			}
			if (adj == true) break;
			tmp += arr[x][y];
		}
		if (adj == true) continue;
		maxn = max(maxn, tmp);
	} while(next_permutation(mask, mask+n*m));
	cout << maxn;
}