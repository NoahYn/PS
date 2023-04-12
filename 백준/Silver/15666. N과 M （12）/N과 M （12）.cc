#include <bits/stdc++.h>
using namespace std;

int n, m;
int sel[10];
int num[10];
bool isused[10];

void print(int m2) {
	if (m2 == m) {
		for (int i = 0; i < m; i++) {
			cout << num[sel[i]] << ' ';
		}
		cout << '\n';
		return ;
	}
	int temp = 0;
	for (int i = sel[m2-1]; i <= n; i++) {
		if (isused[i] == false && num[i] != temp) {
			sel[m2] = i;
//			isused[i] = true;
			temp = num[i];
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
		cin >> num[i];
	}
	sort(num +1, num+n+1);
	int temp = 0;
	for (int i = 1; i <= n; ++i) {
		if (temp == num[i]) continue;
		temp = num[i];
		sel[0] = i;
//		isused[i] = true;
		print(1);
//		isused[i] = false;
	}
}