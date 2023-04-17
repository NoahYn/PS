#include <bits/stdc++.h>
using namespace std;

int A[1000002];
int B[1000002];
int C[2000004];
int n, m;

void merge() {
	int i = 0, j = 0;
	for (int k = 0; k < n+m; k++) {
		if (i == n) {
			for (; j < m; j++) C[k++] = B[j];
			return ;
		}
		if (j == m) {
			for (; i < n; i++) C[k++] = A[i];
			return ;
		}

		if (A[i] > B[j]) C[k] = B[j++];
		else C[k] = A[i++];
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < m; i++) cin >> B[i];
	merge();
	for (int i = 0; i < n+m; i++) cout << C[i] << ' ';
}

