#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	int mn = 0;
	for (int i = 2; i <= n; i++) {
		if (i < k) {
			mn = i;
		}
		else {
			mn = k;
		}
		for (int j = 0; j <= mn; j++) {
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			dp[i][j] %= 10007;
		}
	}
	cout << dp[n][k];
}