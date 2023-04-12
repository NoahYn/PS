
#include <iostream>
#include <set>
using namespace std;

int main() {
	int N; 
	int M; 
	string str;
	set <string> S;
	int count = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		S.insert(str);
	}

	set <string> toCmp;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (S.count(str))
			count++;
	}
	cout << count;
}