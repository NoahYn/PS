#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, h, x;
	cin >> n;
	while (n--) {
		cin >> h >> w >> x;
		int a = 0, b = 1;
		while (x--) {
			if (a < h)
				a++;
			else {
				a = 1;
				b++;
			}
		}
		if (b < 10)
			cout << a << 0 << b << '\n';
		else cout << a << b << '\n';
	}
}