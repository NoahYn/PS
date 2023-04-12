#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	string s;
	bool flag = false;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			flag = false;
		}
		else {
			if (flag == false) { n++;}
			flag = true;
		}
	}
	cout << n;
}