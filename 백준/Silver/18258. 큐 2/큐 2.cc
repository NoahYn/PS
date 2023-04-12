#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int N, num;
	string command;

	cin >> N;
	while (N--) {
		cin >> command;
		if (command.find("push") != string::npos) {
			cin >> num;
			q.push(num);
		}
		else if (command.find("pop") != string::npos) {
			if (q.empty())
				cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (command.find("size") != string::npos)
			cout << q.size() << "\n";
		else if (command.find("empty") != string::npos) {
			if (q.empty()) 
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (command.find("front") != string::npos) {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else if (command.find("back") != string::npos) {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}
	}

}