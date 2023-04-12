#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int w[50][50];
	string s[50];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		fill(w[i], w[i]+m, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 == 0) {
				if (s[i][j] == 'B') {
					w[i][j] = 1;
				}
			}
			else {
				if (s[i][j] == 'W') {
					w[i][j] = 1;
				}
			}
		}
	}
	int ans = 64;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int cnt = 0;
			for (int i2 = 0; i2 < 8; i2++) {
				for (int j2 = 0; j2 < 8; j2++) {
					if (w[i + i2][j + j2])
						cnt++;
				}
			}
			if (cnt > 32)
				ans = min(ans, 64-cnt);
			else
				ans = min(ans, cnt);
		}
	}
	cout << ans;
}