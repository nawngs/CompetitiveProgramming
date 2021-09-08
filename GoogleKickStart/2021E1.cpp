#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

int t;

string s;

string sol(string s) {
	int cnt[130];
	memset(cnt, 0, sizeof(cnt));
	int n = s.size();
	int maxa = 0;
	for (int i = 0; i < n; i++) {
		int tam = s[i];
		cnt[tam] ++;
		maxa = max(maxa, cnt[tam]);
	}
	if (maxa > n / 2) return "IMPOSSIBLE";
	string ans = s;
	for (int i = 0; i < n; i++) {
		if (ans[i] != s[i]) continue;
		for (int j = 0; j < n; j++) {
			if (ans[j] != s[i] && ans[i] != s[j]) {
				swap(ans[j], ans[i]);
				break;
			}
		}
	}
	 return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> s;
		cout << "Case #" << i << ": " << sol(s) << '\n';
	}
}