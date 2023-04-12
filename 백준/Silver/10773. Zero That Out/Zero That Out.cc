#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> account;
	int k, num, sum;
	cin >> k;
	while (k--) {
		cin >> num;
		if (num == 0)
			account.pop();
		else
			account.push(num);
	}
	sum = 0;
	while (!account.empty()) {
		sum += account.top();
		account.pop();
	}
	cout << sum;
}