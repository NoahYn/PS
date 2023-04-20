#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	set<string> s;
	for (int i = 0; i < str.length(); i++) s.emplace(&(str[i]));
	for (auto &k : s) cout << k << '\n';
}