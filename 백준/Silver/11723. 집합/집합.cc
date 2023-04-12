#include<bits/stdc++.h>
using namespace std;

int main(int argc, char * argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int tmp;
	string cmd;
	set<int> s;
	set<int> all;
	for (int i = 1; i <= 20; i++) {
		all.emplace(i);
	}
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd.find("add") != string::npos) {
			cin >> tmp;
			s.emplace(tmp);
		}
		if (cmd.find("remove") != string::npos) {
			cin >> tmp;
			s.erase(tmp);
		}
		if (cmd.find("check") != string::npos) {
			cin >> tmp;
			if (s.find(tmp) != s.end()) cout << "1\n";
			else cout << "0\n";
		}
		if (cmd.find("toggle") != string::npos) {
			cin >> tmp;
			if (s.find(tmp) != s.end()) {
				s.erase(tmp);
			}
			else s.emplace(tmp);
		}
		if (cmd.find("all") != string::npos) {
			s = all;
		}
		if (cmd.find("empty") != string::npos) {
			s.clear();
		}
	}
}
