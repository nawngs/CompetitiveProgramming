#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int nmax = 1e7;
const int MOD = 1;

string s, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> s >> t;
	int ans = INF;
	for (int i = 0 ; i < s.size() - t.size() + 1; ++i) {
		int cnt = 0;
		for (int j = 0; j < t.size(); ++j) {
			if (s[i + j] != t[j]) cnt ++;
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}
