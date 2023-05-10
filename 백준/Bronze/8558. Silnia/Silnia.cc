#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	int ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		if (ans > 10) ans %= 10;
	}
	cout << ans;
}