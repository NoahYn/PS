#include <bits/stdc++.h>
using namespace std;
	
int n, k;
int coins[101];
int dp[10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	fill(dp+1, dp+k+1, 10001);
	for (int j = 0; j < n; j++) {
		for (int i = coins[j]; i <= k; i++) {
			dp[i] = min(dp[i], dp[i-coins[j]]+1);
		}
	}
	if (dp[k] == 10001) cout << -1;
	else cout << dp[k];
}