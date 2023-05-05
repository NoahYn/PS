#include <bits/stdc++.h>
using namespace std;

int arr[10000];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i-1]) {
			prev_permutation(arr, arr+n);
			for (int i = 0; i < n; i++) cout << arr[i] << ' ';
			return 0;
		}
	}
	cout << -1;
}