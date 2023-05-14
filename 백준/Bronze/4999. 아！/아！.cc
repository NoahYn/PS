#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	string s2;
	cin >> s >> s2;
	if (s.size() >= s2.size())
		cout << "go";
	else
		cout << "no";
}