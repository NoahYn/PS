#include <bits/stdc++.h>
using namespace std;

int arr[1000002];
int tmp[1000002];
int n;

void merge(int s, int e) {
	int m = (e+s)/2;
	int i = s;
	int j = m;
	for (int k = s; k < e; k++) {
		if (i == m) tmp[k] = arr[j++];
		else if (j == e) tmp[k] = arr[i++];
		else if (arr[i] <= arr[j]) tmp[k] = arr[i++];
		else tmp[k] = arr[j++];
	}
	for (int k = s; k < e; k++) arr[k] = tmp[k];
}

void mergeSort(int s, int e) {
	if (e-s < 2) return ;
	int m = (e+s)/2;
	mergeSort(s, m);
	mergeSort(m, e);
	merge(s, e);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	mergeSort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}

