#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (a > b) {
		if (b == 0) return a;
		return (gcd(a%b, b));
	}
	else {
		if (a == 0) return b;
		return (gcd(b%a, a));
	}
}

int lcm(int a, int b) {
	return (a/gcd(a,b)*b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		if (m == x) x = 0;
		if (n == y) y = 0;
		int flag = 1;
		int LCM = lcm(m,n);
		for (int i = x; i <= LCM; i += m) {
			if (i == 0) continue;
			if (i % n == y) {
				cout << i << '\n';
				flag = 0;
				break;
			}
		}
		if (flag) cout << -1 << '\n';
	}
}