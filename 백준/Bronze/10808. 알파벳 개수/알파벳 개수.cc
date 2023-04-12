#include <iostream>

using namespace std;

int main() {
	string s;
	int alpha_num[26] = { 0 };
	cin >> s;
	for (auto i : s) {
		alpha_num[i - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alpha_num[i] << ' ';
	}
	return 0;
}