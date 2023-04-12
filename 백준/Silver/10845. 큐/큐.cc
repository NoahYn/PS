#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> d;
	string s;
	int n, arg;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.find("push") != string::npos) {
			cin >> arg;
			d.push_back(arg);
		}
		else if (s.find("pop") != string::npos) {
			if (d.empty()) cout << "-1\n";
			else {	cout << d.front() << "\n";
				d.pop_front();
			} 
		}
		else if (s.find("front") != string::npos) {
			if (d.empty()) cout << "-1\n";
			else cout << d.front() << "\n";
		}
		else if (s.find("back") != string::npos) {
			if (d.empty()) cout << "-1\n";
			else cout << d.back() << "\n";
		}
		else if (s.find("size") != string::npos) {
			cout << d.size() << '\n';
		}
		else if (s.find("empty") != string::npos) {
			if (d.empty()) cout << "1\n";
			else cout << "0\n";
		}
	}
}