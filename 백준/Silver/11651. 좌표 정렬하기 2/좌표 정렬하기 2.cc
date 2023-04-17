#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

pair<int, int> yx[100001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> yx[i].second >> yx[i].first;
	}
	sort(yx, yx+n);
	for (int i = 0; i < n; i++) {
		cout << yx[i].second << ' ' << yx[i].first << '\n';
	}
}