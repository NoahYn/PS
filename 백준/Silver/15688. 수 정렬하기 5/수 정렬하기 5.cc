#include <bits/stdc++.h>
using namespace std;

int arr[2000002];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num+1000000]++;
	}
	for (int i = 0; i < 2000001; i++) {
		while (arr[i]--) cout << i - 1000000 << '\n';
	}
}