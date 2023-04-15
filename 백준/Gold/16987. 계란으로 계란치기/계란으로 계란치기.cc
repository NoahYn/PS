#include <bits/stdc++.h>
using namespace std;

#define X first // durability
#define Y second // weight

int n, ans = 0;
int isused;
pair<int,int> eggs[10];

void rec(int idx) {
	if (idx >= n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) 
			if (eggs[i].X <= 0) 
				cnt++;
		ans = max(ans, cnt);
		return;
	}
	if (eggs[idx].X <= 0) { 
		rec(idx+1);
		return; 
	}
	
	for (int i = 0; i < n; i++) {
		if (isused < 2) { rec(n); return;}
		if (i == idx || eggs[i].X <= 0) continue;
		eggs[i].X -= eggs[idx].Y;
		eggs[idx].X -= eggs[i].Y;
		if (eggs[i].X <= 0) isused--;
		if (eggs[idx].X <= 0) isused--;
		rec(idx+1);
		if (eggs[i].X <= 0) isused++;
		if (eggs[idx].X <= 0) isused++;
		eggs[i].X += eggs[idx].Y;
		eggs[idx].X += eggs[i].Y;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) { 
		int durabl, weight;
		cin >> durabl >> weight;
		eggs[i] = make_pair(durabl, weight);
	}
	isused = n;

	rec(0);

	cout << ans;
}