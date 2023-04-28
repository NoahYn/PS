#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, k;
int val[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int cnt = 0;
	int i;
	for (i = 0; i < n; i++) {
		cin >> val[i];
	}

	i--;
	while (k) {
		if (k >= val[i]) {
			k -= val[i];
			cnt++;
		}
		else {
			while (k < val[i]) i--;
		}
	}
	cout << cnt;
}
