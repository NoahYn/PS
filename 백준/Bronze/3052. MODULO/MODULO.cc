#include<bits/stdc++.h>
using namespace std;

int a[42];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;
		a[temp%42]++;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (a[i] > 0) cnt++;
	}
	cout << cnt;
}