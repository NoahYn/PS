#include <bits/stdc++.h>
using namespace std;

int len, n;
char str[15];
char sel[15];
bool isused[15];

void rec(int idx) {
	if (idx == len) {
		int vowel = 0;
		int nvowel = 0;
		for (int i = 0; i < len; i++) {
			if (sel[i] == 'a' || sel[i] == 'e' || sel[i] == 'i' || sel[i] == 'o' || sel[i] == 'u') vowel++;
			else nvowel++;
		}
		if (vowel < 1 || nvowel < 2) return;
		cout << sel << '\n';
		return ;
	}
	for (int i = idx; i < n; i++) {
		if (isused[i] == true || sel[idx-1] > str[i]) continue;
		isused[i] = true;
		sel[idx] = str[i];
		rec(idx+1);
		isused[i] = false;
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> len >> n;
	for (int i = 0; i < n; i++) cin >> str[i];
	sel[n] = '\0';
	sort(str, str+n);
	rec(0);
}