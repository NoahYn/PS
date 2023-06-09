#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int src, dst;
		cin >> src >> dst;
		dst -= src; // diff
		int n = sqrt(dst);
		int move = 2*n-1;
		long long rem = dst - n*n;
		rem = (long long)ceil((double)rem / (double)n);
		cout << move + rem << '\n';
	}
}