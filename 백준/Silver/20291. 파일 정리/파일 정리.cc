#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int n;
	map <string, int> files;
	map <string, int> ::iterator itr;
	pair <string, int> extender;
	string fileName;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> fileName;
		extender.first = fileName.substr(fileName.find('.') + 1, fileName.length());
		
		itr = files.find(extender.first);
		if (itr != files.end())
			itr->second++;
		else
			files.emplace(extender.first, 1);
	}
	for (itr = files.begin(); itr != files.end(); itr++) {
		cout << itr->first << " " << itr->second << "\n";
	}
}