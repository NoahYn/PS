#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100001];
int sum[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = arr[i] + sum[i-1];
	}
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i-1] << '\n';
	}
}