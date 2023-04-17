#include <bits/stdc++.h>
using namespace std;

int arr[3003];
int n;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void insertionSort(int left, int right) {
	for (int i = left; i < right; i++) {
		int ist = i;
		for (int j = i+1; j <= right; j++) {
			if (arr[ist] > arr[j]) ist = j;
		}
		if (ist != i) swap(arr[ist], arr[i]);		
	}
}

void quickSort(int left, int right) {
	if (right - left == 0) return ;
	if (right - left < 5) {
		insertionSort(left, right);
		return ;
	}
	int pvt;
	int mdn[3] = {left, right, (left+right)/2};
	if (arr[mdn[0]] > arr[mdn[1]] && arr[mdn[0]] < arr[mdn[2]]) pvt = mdn[0];
	else if (arr[mdn[1]] > arr[mdn[2]] && arr[mdn[1]] < arr[mdn[0]]) pvt = mdn[1];
	else pvt = mdn[2];
	int pvtItem = arr[pvt];
	int i = left;
	int j = right;
	while (i < j) {
		while (arr[i] < pvtItem) i++;
		while (arr[j] > pvtItem) j--;
		if (i < j) swap(arr[i], arr[j]);
	}
	pvt = i;
	quickSort(left, pvt-1);
	quickSort(pvt+1, right);
}

	int main(void){
		ios::sync_with_stdio(0);
		cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	quickSort(0, n-1);
	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}

