#include <bits/stdc++.h>
using namespace std;

pair<int, int> fibo[42];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	fibo[0] = make_pair(1, 0);
	fibo[1] = make_pair(0, 1);
	for (int i = 2; i <= 40; i++) {
		fibo[i].first = fibo[i-1].first + fibo[i-2].first;
		fibo[i].second = fibo[i-1].second + fibo[i-2].second;
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << fibo[n].first << ' ' << fibo[n].second << '\n';
	}
}