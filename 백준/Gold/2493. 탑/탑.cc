#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, temp, lazer_height;
	vector<pair<int, int>>::iterator lazer_pos;
	vector<pair<int, int>> tower;
	cin >> n;
	tower.push_back(make_pair(100000001, 0));
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		tower.push_back(make_pair(temp, i));
		lazer_pos = --tower.end();
		lazer_height = lazer_pos->first;
		--lazer_pos;
		do {
			if (lazer_pos->first > lazer_height) {
				cout << lazer_pos->second << " ";
				break;
			}
			while (lazer_pos->first < lazer_height) {
				tower.erase(lazer_pos);
			}
		} while (lazer_pos-- != tower.begin());
	}
}