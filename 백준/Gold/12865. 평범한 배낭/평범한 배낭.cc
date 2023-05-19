#include <bits/stdc++.h>
using namespace std;

int DP[101][100001];
int val[100];
int wgh[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> wgh[i] >> val[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (wgh[i-1] <= j) {
				DP[i][j] = max(DP[i-1][j-wgh[i-1]] + val[i-1], DP[i-1][j]);
			}
			else 
				DP[i][j] = DP[i-1][j];
		}
	}
	int mx = 0;
	
	//for (int i = 1; i <= w; i++) 
	//	cout << i << ' '; 
	//	cout << '\n';
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= w; j++) {
	//		cout << DP[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	for (int i = 1; i <= w; i++) {
		mx = max(mx, DP[n][i]);
	}
	cout << mx;
}