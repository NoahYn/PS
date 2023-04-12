#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		int n;
		cin >> n;
		if (ans < n) {
			ans = n;
			idx = i;
		}
	}
	cout << ans << "\n" << idx + 1;
}