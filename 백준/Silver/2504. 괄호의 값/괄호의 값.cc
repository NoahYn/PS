#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	int score = 1;
	string brackets;
	cin >> brackets;
	stack<char> s2; // ()
	stack<char> s3; // []
	for (int i = 0; i < brackets.size(); i++) {
		if (brackets[i] == '(') {
			s2.push(brackets[i]);
			score *= 2;
		}
		else if (brackets[i] == '[') {
			s3.push(brackets[i]);
			score *= 3;
		}
		else if (brackets[i] == ')') {
			if (s2.empty()) {
				ans = 0;
				break ;	
			}
			s2.pop();
			if (brackets[i-1] == '(')
				ans += score;
			score /= 2;
		}
		else if (brackets[i] == ']') {
			if (s3.empty()) {
				ans = 0;
				break ;
			}
			s3.pop();
			if (brackets[i-1] == '[')
				ans += score;
			score /= 3;
		}
	}
	if (!s2.empty() || !s3.empty())
		ans = 0;
	cout << ans;
}
