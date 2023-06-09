#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int next = 4;
	int ans = 1;
	while (n--) {
		ans += next;
		next += 3;
		ans %= 45678;
	}
	cout << ans;
}
