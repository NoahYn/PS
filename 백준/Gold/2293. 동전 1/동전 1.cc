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
	dp[0] = 1;
	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= k; i++) {
			if (coins[j] <= i) {
				dp[i] += dp[i-coins[j]];
			}
		}
	}

	cout << dp[k];
}