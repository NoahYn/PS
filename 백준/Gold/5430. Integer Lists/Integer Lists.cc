#include <bits/stdc++.h>
using namespace std;

void parse(string& tmp, deque<int>& d){
  int cur = 0;
  for(int i = 1; i+1 < tmp.size(); i++)
  {
    if(tmp[i] == ','){
      d.push_back(cur);
      cur = 0;
    }
    else{
      cur = 10 * cur + (tmp[i] - '0');
    }
  }
  if(cur != 0)
    d.push_back(cur);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n; 
	bool rev;
	string p, buff;

	cin >> t;
	while (t--) {
		deque<int> d;
		rev = false;
		cin >> p >> n >> buff;
		if (n < count(p.begin(), p.end(), 'D')) {
			cout << "error\n";
			continue;
		}
		parse(buff, d);
		for (char c : p) {
			if (c == 'R') rev = (rev == true ? false : true);
			else {
				if (!rev) d.pop_front();
				else d.pop_back();
			}
		}
		if (rev) reverse(d.begin(), d.end());
		cout << "[";
		for (int i = 0; i < d.size(); i++) {
			cout << d[i];
			if (i+1 != d.size())
				cout << ',';
		}
		cout << "]\n";
	}	
}
