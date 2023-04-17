#include <bits/stdc++.h>
using namespace std;

string s[50];

bool cmp(string &a, string &b) {
	if (a.length() != b.length()) return a.length() < b.length();
	else {
		int suma = 0, sumb = 0;
		for (char i = '1'; i <= '9'; i++) {
			suma += count(a.begin(), a.end(), i) * (i - '0');
			sumb += count(b.begin(), b.end(), i) * (i - '0');
		}
		if (suma != sumb) return suma < sumb;
		else return (a < b);
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	sort(s, s+n, cmp);
	for (int i = 0; i < n; i++) cout << s[i] << '\n';

}

