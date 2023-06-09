#include <bits/stdc++.h>
using namespace std;
	
int dp[1000];
int seq[1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (seq[i] < seq[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		if (dp[i] == 0) dp[i] = 1;
	}
	int *ans = max_element(dp, dp+n);
	cout << *ans;
}