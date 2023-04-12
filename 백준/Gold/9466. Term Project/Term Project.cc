#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
int n, t;
int arr[100001];
int state[100001];

const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE = 2;
const int NOT_CYCLE = 3;

void run(int x) {
	int cur = x;
	while (true) {
		state[cur] = VISITED;
		cur = arr[cur];
		if (state[cur] == CYCLE || state[cur] == NOT_CYCLE) {
			cur = x;
			while (state[cur] == VISITED) {
				state[cur] = NOT_CYCLE;
				cur = arr[cur];
			}
			return;
		}
		if (state[cur] == VISITED && cur == x) {
			while(state[cur] != CYCLE) {
				state[cur] = CYCLE;
				cur = arr[cur];
			}
			return ;
		}
		if (state[cur] == VISITED && cur != x) {
			while(state[cur] != CYCLE) {
				state[cur] = CYCLE;
				cur = arr[cur];
			}
			cur = x;
			while(state[cur] != CYCLE) {
				state[cur] = NOT_CYCLE;
				cur = arr[cur];
			}
			return;
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		fill(state+1, state+n+1, NOT_VISITED);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (state[i] == NOT_VISITED) run(i);
		}
		cout << count(state+1, state+n+1, NOT_CYCLE) << '\n';
	}
}