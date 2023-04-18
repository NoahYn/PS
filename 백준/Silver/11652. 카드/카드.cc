#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

long long card[MAX];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> card[i];
	sort(card, card+n);

	int i = 0;
	int cnt = 0;
	long long ans = card[i];
	while (ans == card[i]) {
		cnt++;
		i++;
	}

	int max = cnt;
	cnt = 0;
	long long tmp = card[i];
	for (; i < n; i++) {
		if (card[i] == tmp) cnt++;
		else {
			if (max < cnt) {
				max = cnt;
				ans = tmp;
			}
			tmp = card[i];
			cnt = 1;
		}
	}
	if (max < cnt) {
		max = cnt;
		ans = tmp;
	}
	cout << ans;	
}