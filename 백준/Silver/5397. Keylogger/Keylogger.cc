#include <list>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string str;
	list<char> pwd;
	list<char>::iterator it;
	cin >> n;
	while (n--) {
		cin >> str;
		pwd.clear();
		it = pwd.begin();
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {
				if (pwd.begin() != it)
					--it;
			}
			else if (str[i] == '>') {
				if (pwd.end() != it)
					++it;
			}
			else if (str[i] == '-') {
				if (pwd.begin() != it) 
				{
					--it;
					it = pwd.erase(it);
				}
			}
			else {
				pwd.insert(it, str[i]);
			}
		}
		for (auto c : pwd) {
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}