#include <bits/stdc++.h>
using namespace std;

int cnt[10001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num; cnt[num]++;
	}
	for (int i = 1; i <= 10000; i++) {
		while (cnt[i]--) cout << i << '\n';
	}
}