#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<tuple<int,int,int>> cctv;
int n, m;

int watch(int x, int y, int arr[][8], int dir) {
	int rblind = 0;

	if (dir == 0) { // down
		for (int i = x + 1; i < n; i++) {
			if (arr[i][y] == 6) break;
			else if (arr[i][y] == 0) {
				arr[i][y]--;
				rblind++;
			}
		}
	} 
	else if (dir == 1) { // up
		for (int i = x - 1; i >= 0; i--) {
			if (arr[i][y] == 6) break;
			if (arr[i][y] == 0) {
				arr[i][y]--;
				rblind++;
			}
		}
	}
	else if (dir == 2) { // right
		for (int j = y + 1; j < m; j++) {
			if (arr[x][j] == 6) break;
			if (arr[x][j] == 0) {
				arr[x][j]--;
				rblind++;
			}
		}
	}
	else {	// left
		for (int j = y - 1; j >= 0; j--) {
			if (arr[x][j] == 6) break;
			if (arr[x][j] == 0) {
				arr[x][j]--;
				rblind++;
			}
		}
	}
	return rblind;
}

int solve(int idx, int blind, int arr[][8]) {
	int arr2[8][8];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr2[i][j] = arr[i][j];
		}
	}
	int n, i, j;
	for (int k = 0; k < cctv.size(); k++) {
		tie(n, i, j) = cctv[k];
		if (n == 1) {
			if (idx % 4 == 0) blind -= watch(i, j, arr2, 0);
			else if (idx % 4 == 1) blind -= watch(i, j, arr2, 1);
			else if (idx % 4 == 2) blind -= watch(i, j, arr2, 2);
			else blind -= watch(i, j, arr2, 3);	
		}
		if (n == 2) {
			if (idx % 2 == 0) {
				blind -= watch(i, j, arr2, 0);
				blind -= watch(i, j, arr2, 1);
			}
			else {
				blind -= watch(i, j, arr2, 2);
				blind -= watch(i, j, arr2, 3);
			}	
		}
		if (n == 3) {
			if (idx % 4 == 0) {
				blind -= watch(i, j, arr2, 1);
				blind -= watch(i, j, arr2, 2);
			}
			else if (idx % 4 == 1) {
				blind -= watch(i, j, arr2, 2);
				blind -= watch(i, j, arr2, 0);
			}
			else if (idx % 4 == 2) {
				blind -= watch(i, j, arr2, 0);
				blind -= watch(i, j, arr2, 3);
			}
			else {
				blind -= watch(i, j, arr2, 3);
				blind -= watch(i, j, arr2, 1);
			}
		}
		if (n == 4) {
			if (idx % 4 == 0) {
				blind -= watch(i, j, arr2, 1);
				blind -= watch(i, j, arr2, 2);
				blind -= watch(i, j, arr2, 3);
			}
			else if (idx % 4 == 1) {
				blind -= watch(i, j, arr2, 0);
				blind -= watch(i, j, arr2, 2);
				blind -= watch(i, j, arr2, 3);
			}
			else if (idx % 4 == 2) {
				blind -= watch(i, j, arr2, 0);
				blind -= watch(i, j, arr2, 1);
				blind -= watch(i, j, arr2, 3);
			}
			else {
				blind -= watch(i, j, arr2, 0);
				blind -= watch(i, j, arr2, 1);
				blind -= watch(i, j, arr2, 2);
			}
		}
		idx /= 4;
	}

	return blind;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int blind = n * m;
	int arr[8][8];
	vector<pair<int,int>> cctv5;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) blind--;
			if (arr[i][j] > 0 && arr[i][j] < 5) {
				cctv.push_back(make_tuple(arr[i][j], i, j));
			}
			else if (arr[i][j] == 5) {
				cctv5.push_back({i,j});
			}
		}
	}
	
	// cctv 5
	for (pair<int,int> p : cctv5) {
		for (int dir = 0; dir < 4; dir++) {
			blind -= watch(p.X, p.Y, arr, dir);
		}
	}

	int p = 1 << (2*cctv.size());
	int temp = blind;
	for (int i = 0; i < p; i++) {
		blind = min(blind, solve(i, temp, arr));
	}
	cout << blind;
}