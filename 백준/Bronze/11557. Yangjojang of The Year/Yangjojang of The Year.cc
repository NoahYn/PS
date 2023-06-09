#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, string, greater<int>> m;
		for (int i =0; i < n; i++)  {
			string s;
			int amount;
			cin >> s >> amount;
			m.emplace(amount, s);
		}
		cout << m.begin()->second << '\n';
	}
}