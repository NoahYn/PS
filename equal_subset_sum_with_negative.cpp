/*
name : Sungmin Yoon
student ID : 2021202033
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXSUM 125250 // (sum of 1 to 500)
#define NUM 500

int setA[NUM];
bool issetB[NUM];
unsigned long long DP[NUM+1][MAXSUM+1]; // using 0 ~ NUM-th item, sum(0 ~ MAXSUM)
unsigned long long nDP[NUM+1][MAXSUM+1]; // using 0 ~ NUM-th item, sum(0 ~ -MAXSUM)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n) {
		if (n == 0) return 0; // end of input
		int psum = 0; // sum of positive element
		int nsum = 0; // sum of negative element
		int sum = 0; 
		int neg_num = 0;
		int pos_num = 0;
		bool numerous = false;
		ssize_t cnt = 0;

		for (int i = 0; i < n; i++) {
			cin >> setA[i];
//			setA[i] = (i+1) * ((i%2) ? -1 : 1);
//			setA[i] = (i+1);
			if (setA[i] > 0) 
				psum += setA[i];	
			else {
				nsum -= setA[i];
				neg_num++;
			}
		}
		sum = psum - nsum;
		pos_num = n - neg_num;

		sort(setA, setA+n, less<int>());
		for (int i = 0; i <= pos_num; i++) 
			DP[i][0] = 1;
		for (int i = 0; i <= neg_num; i++) 
			nDP[i][0] = 1;

		for (int i = 1; i <= neg_num; i++) {
			for (int j = 1; j <= nsum; j++) {
				nDP[i][j] += nDP[i-1][j];
				if (-setA[i-1] <= j) {
					nDP[i][j] += nDP[i-1][j+setA[i-1]];
				}
				if (nDP[i][j] > UINT_MAX) 
					numerous = true;
			}
		}

		for (int i = 1; i <= pos_num; i++) {
			for (int j = 1; j <= psum; j++) {
				DP[i][j] += DP[i-1][j];
				if (setA[i+neg_num-1] <= j) {
					DP[i][j] += DP[i-1][j-setA[i+neg_num-1]];
				}
				if (DP[i][j] > UINT_MAX)
					numerous = true;
			}
		}
		// i%2로 배열 숫자줄이기 

		if (sum & 1) // sum is odd : can not divide into two equal sum subset
			cout << "0\n";
		else {
			if (sum > 0) {
				for (int i = 0; i <= psum && i <= nsum; i++) {
					if (DP[pos_num][sum/2 + i] && nDP[neg_num][i]) {
						cnt += DP[pos_num][sum/2 + i] * nDP[neg_num][i];
						if (cnt/2 > UINT_MAX || DP[pos_num][sum/2 + i] * nDP[neg_num][i] /2 > UINT_MAX) {
							numerous = true;
							break;
						}
					}
				}
			}
			else {
				for (int i = 0; i <= psum && i <= nsum; i++) {
					if (DP[pos_num][i] && nDP[neg_num][i - (sum/2)]) {
						cnt += DP[pos_num][i] * nDP[neg_num][i - (sum/2)];
						if (cnt/2 > UINT_MAX || DP[pos_num][i] * nDP[neg_num][i - sum/2] /2 > UINT_MAX) {
							numerous = true;
							break;
						}
					}
				}
			}

			if (numerous)
				cout << "NUMEROUS\n";
			else
				cout << cnt/2 << '\n';
		}

		int sumA = 0, sumB = 0;
		for (int i = 0; i < neg_num; i++) { // negative number
			if (sumA <= sumB) { 
				sumB += setA[i]; 
				issetB[i] = true;
			}
			else 
				sumA += setA[i];
		}
		for (int i = n-1; i >= neg_num; i--) { // positive number, check from back because it is sorted in acsending order 
			if (sumA >= sumB) {
				sumB += setA[i];
				issetB[i] = true;
			}
			else 
				sumA += setA[i];
		}

		int numB = count(issetB, issetB+n, true);
		int numA = n-numB;
		cout << "{";
		for (int i = 0; i < n; i++) {
			if (!issetB[i]) {
				cout << setA[i];
				if (--numA)
					cout << ',';
			}
		}
		cout << "},{";
		for (int i = 0; i < n; i++) {
			if (issetB[i]) {
				cout << setA[i];
				if (--numB)
					cout << ',';
			}
		}
		cout << "}\n";

		fill(issetB, issetB+n, false);
		if (psum)
			for (int i = 0; i <= pos_num; i++) 
				fill(DP[i], DP[i]+psum+1, 0);
		if (nsum)
			for (int i = 0; i <= neg_num; i++) 
				fill(nDP[i], nDP[i]+nsum+1, 0);
	}
}
