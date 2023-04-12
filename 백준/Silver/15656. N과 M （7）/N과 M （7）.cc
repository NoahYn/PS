#include <bits/stdc++.h>
using namespace std;

int n, m;
int sel[10];
bool isused[10];
int element[10];

void print(int m2) {
	if (m2 == m) {
		for (int i = 0; i < m; i++) {
			cout << element[sel[i]] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (isused[i] == false) {
			sel[m2] = i;
//			isused[i] = true;
			print(m2+1); 
//			isused[i] = false;
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> element[i];
	}
	sort(element +1, element+n+1);
	for (int i = 1; i <= n; ++i) {
		sel[0] = i;
//		isused[i] = true;
		print(1);
//		isused[i] = false;
	}
}
