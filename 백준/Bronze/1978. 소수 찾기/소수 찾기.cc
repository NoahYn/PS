#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, temp;
	int ans = 0;
	cin >> n;
	while (n--) {
		cin >> temp;
		if (temp < 4) {
			if (temp == 1) continue;
			ans++;
		}
		else {
			ans++;
			for (int i = 2; i <= sqrt(temp); i++) {
				if (temp % i == 0) {
					ans--;
					break;
				}
			}
		}
	}
	cout << ans;
}