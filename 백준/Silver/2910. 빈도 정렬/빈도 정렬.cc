#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int n, c;
map<int, double> m;

bool freq(int &a, int &b) {
	return (m[a] > m[b]);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		if (m.find(arr[i]) != m.end()) continue;
		int cnt = count(arr, arr+n, arr[i]);
		double order = cnt + (double)(n-i-1)/n;
		m.emplace(arr[i], order);
	}
	sort(arr, arr+n, freq);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}