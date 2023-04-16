#include <bits/stdc++.h>
using namespace std;

#define R 0
#define G 1
#define B 2

int n;
int rgb[1002][3];
int ans[1002][3];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> rgb[i][R];
		cin >> rgb[i][G];
		cin >> rgb[i][B];
	}
	ans[1][R] = rgb[1][R];
	ans[1][G] = rgb[1][G];
	ans[1][B] = rgb[1][B];
	for (int i = 2; i <= n; i++) {
		ans[i][R] = rgb[i][R] + min(ans[i-1][G], ans[i-1][B]);
		ans[i][G] = rgb[i][G] + min(ans[i-1][R], ans[i-1][B]);
		ans[i][B] = rgb[i][B] + min(ans[i-1][G], ans[i-1][R]);
	}
	cout << min(ans[n][R], min(ans[n][G], ans[n][B]));
}