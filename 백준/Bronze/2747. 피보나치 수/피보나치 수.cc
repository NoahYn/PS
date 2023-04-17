#include <bits/stdc++.h>
using namespace std;

#define ll long long 

class matrix {
public:
	ll mat[2][2] = {{1,0}, {0,1}};
	ll tmp[2][2] = {{1,1}, {1,0}};
};

matrix mat;

void squared_matmul(int m) {
	ll out[2][2];
	if (m == 0) {
		for (ll i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				out[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					out[i][j] += mat.mat[i][k] * mat.tmp[k][j];
				}
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				mat.mat[i][j] = out[i][j];
			}
		}	
	}
	else {
		for (ll i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				out[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					out[i][j] += mat.tmp[i][k] * mat.tmp[k][j];
				}
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				mat.tmp[i][j] = out[i][j];
			}
		}	
	}
}

long long fibo(ll n) {
	if (n == 0) return 0;
	if (n == 1 || n == 2) return 1;
	
	for (ll i = 0; i * i <= n+1; i++) {
		if (n & (1 << i)) squared_matmul(0);
		squared_matmul(1);
	}

	return (mat.mat[1][0]);
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;
	cout << fibo(n);
	return 0;
}