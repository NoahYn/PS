#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[100002];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s, d, s2;
	queue<int> q;
	cin >> s >> d;
	fill(dist, dist+100001, -1);
	dist[s] = 0;
	s2 = s * 2;
	while (s2 < 100001 && s2 > 0) {
		dist[s2] = 0;
		if (s2 == d) {
			cout << 0;
			return 0;
		}
		q.push(s2);
		s2 *= 2;
	}
	q.push(s);
	while (!q.empty()) {
		s = q.front(); q.pop();
		for (int next : {s-1, s+1}) {
			if (next < 0 || next > 100000) continue;
			if (dist[next] != -1) continue;
			if (next == d) {
				cout << dist[s]+1;
				return 0;
			}
			dist[next] = dist[s]+1;
			s2 = next * 2;
			while (s2 < 100001 && s2 > 0 && dist[s2] == -1) {
				dist[s2] = dist[next];
				if (s2 == d) {
					cout << dist[next];
					return 0;
				}
				q.push(s2);
				s2 *= 2;
			}
			q.push(next);
		}
	}
	cout << dist[d];
}