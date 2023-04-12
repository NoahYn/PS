#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans = 0;
	string word;
	cin >> n;
	while(n--) {
		stack<char> s;
		cin >> word;
		for (int i = 0; i < word.size(); i++) {
			if (s.empty())	s.push(word[i]);
			else {
				if (s.top() == word[i])	s.pop();
				else s.push(word[i]);
			}
		}
		if (s.empty()) ++ans;
	}	
	cout << ans;
}
