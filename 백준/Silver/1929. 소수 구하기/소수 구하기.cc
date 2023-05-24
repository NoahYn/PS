#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	vector<bool> isprime(n+1, true);
	isprime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (!isprime[i]) continue;
		for (int j = i; j * i<= n; j++) {
			isprime[j*i] = false;
		}
	}
	for (int i = m; i <= n; i++) {
		if (isprime[i] == true)
			cout << i <<'\n';
	}
}