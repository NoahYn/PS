#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string tmp;
	multiset<long long> s;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		reverse(tmp.begin(), tmp.end());
		long long stoi = 0;
		for (int i = 0; i < tmp.length(); i++) {
			stoi = stoi * 10 + tmp[i] - '0';
		}
		s.emplace(stoi);
	}
	for (auto &k : s) {
		cout << k << '\n';
	}
}