#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;
	int value;
	priority_queue<int> pq;

	cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		cin >> value;
		v.push_back(value);
	}

	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			if (pq.empty())
				cout << 0;
			else {
				cout << pq.top();
				pq.pop();
			}
			cout << "\n";
		}
		else
			pq.push(v[i]);
	}

	return 0;
}