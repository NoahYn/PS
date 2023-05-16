#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	double a;
	double b;
	cin >> a >> b;
	a -= (a / 100 * b);
	cout << (a < 100);
}