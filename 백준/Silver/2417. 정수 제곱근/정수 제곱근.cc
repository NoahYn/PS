#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ULL n;
	cin >> n;

	ULL low = 0, upp = 3037000500;
	ULL mid = upp / 2;
	while (low <= upp) {
		if (mid * mid > n) upp = mid - 1;
		else low = mid + 1;
		mid = (low + upp)/2; 
	}
	if (mid * mid == n)	cout << mid;
	else cout << mid+1;
}