#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	multiset<pair<int,int>> m;
	int time;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		m.emplace(e,s);
	}
	for (auto k : m) {
		if (cnt == 0) {
			cnt++;
			time = k.X;
		}
		else if (k.Y >= time) {
			cnt++;
			time = k.X;
		}
	}
	cout << cnt;
}