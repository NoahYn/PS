#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long n, m;
	cin >> n >> m;
	if (n > m) {
		int temp = n;
		n = m;
		m = temp;
	}
	else if (n == m) {
		cout << 0;
		return 0;
	}
	cout << m-n-1 << '\n';
	for (unsigned long long i = n+1; i < m; i++) {
		cout << i << ' ';
	}
}