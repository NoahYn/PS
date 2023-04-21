#include <bits/stdc++.h>
using namespace std;

int a[20001];
int b[20001];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		int tmp;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(a, a+n);
		sort(b, b+m);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (a[i] <= b[j]) break;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
}