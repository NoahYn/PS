#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int k;
	list<int> cl;
	list<int>::iterator it;

	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cl.push_back(i);
	}
	it = cl.end();
	--it;
	cout << "<"; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (++it == cl.end()) {
				it = cl.begin();
			}
		}
		cout << *it;
		if (i >= 0 && i < n-1)
			cout << ", ";
		it = cl.erase(it);
		--it;
	}
	cout << ">";
}  