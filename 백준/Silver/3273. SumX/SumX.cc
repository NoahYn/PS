#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	int a;
	int x;
	cin >> n;
	vector <int> seq(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		seq[i] = a;
	}
	cin >> x;
	vector <int> sum(x + 1, 0);
	for (int i = 0; i < n; i++) {
		if (seq[i] >= x)
			continue;
		sum[seq[i]]++;
	}
	for (int i = 1; i < (x+1) / 2; i++) {
		if (sum[i] && sum[x - i]) {
			sum[x]++;
		}
	}
	cout << sum[x];
	return 0;
}