#include <bits/stdc++.h>
using namespace std;

bool mask[9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m,k;
	cin >> n >> m >> k;
	int tot = 0;
	int tr = 0;
	fill(mask+n-m, mask+n, true);
	do {
		int k2 = 0;
		for (int i = 0; i < m; i++) {
			if (mask[i] == true) {
				k2++;
				if (k2 == k) {
					tr++;
					break;
				}
			}
		}
		tot++;
	} while(next_permutation(mask, mask+n));
	double ans = (double)tr / tot;
	cout.precision(16);
	cout << ans;
}
