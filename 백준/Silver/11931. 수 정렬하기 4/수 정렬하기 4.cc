#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000

bool cnt[2000002];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num; cnt[num + MAX] = true;
	}
	for (int i = MAX; i >= -MAX; i--) {
		if(cnt[i + MAX] == true) cout << i << '\n';
	}
}