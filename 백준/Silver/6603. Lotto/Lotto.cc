#include <bits/stdc++.h>
using namespace std;

int n, arr[15], mask[15];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> n) {
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 6; i < n; i++) {
			mask[i] = 1;
		}
		do {
			for (int i = 0; i < n; i++) {
				if (!mask[i]) cout << arr[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(mask, mask+n));
		cout << '\n';
	}
}