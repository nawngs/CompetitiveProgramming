#include <bits/stdc++.h>

using namespace std;

const int N = 100;

string s, dp[N + 3][5];

char c;

void tham() {
	for (int i = s.size() - 1; i >= 0; i--) if (s[i] == '5') {
		for (int j = 0; j <= i; j++) cout << s[j];
		cout << '\n';
		return ;
	}
}

void minimize(string &s, string t) {
	if (s == "#" || s.size() < t.size()) {
		s = t;
		return ;
	}
	if (s.size() > t.size()) return ;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] > t[i]) return ;
		if (s[i] < t[i]) {
			s = t;
			return ;
		}
	}
}

void qhd() {
	int n = s.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++) dp[i][j] = "#";
	dp[0][0] = "";
	dp[0][(s[0] - '0') % 3] = s[0];
	for (int i = 0; i < n - 1; i++)
	for (int j = 0; j < 3; j++) {
		if (dp[i][j] == "#") continue;
		int c = s[i + 1] - '0';
		minimize(dp[i + 1][(j % 10 + c) % 3], dp[i][j] + s[i + 1]);
		minimize(dp[i + 1][j], dp[i][j]);
	}	
	cout << dp[n - 1][0] << '\n';
}

void solve() {
	cin >> s >> c;
	if (c == '0') tham();
	else qhd();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("b2.inp", "r", stdin);
	freopen("b2.out", "w", stdout);
	int t; cin >> t;
	while (t--) solve();
}