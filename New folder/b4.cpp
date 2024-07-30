#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

int k;

string s1, s2;

namespace sub1 {
	bool check() {
		if (k == 1) return true;
		else return false;
	}
	void solve() {
		cin >> s1;
		int cur = 1;
		for (int i = 0; i < s1.size(); i++) {
			char c = s1[i];
			if (c == 'B' && cur % 2 == 1) cur ++;
			if (c == 'R' && cur % 2 == 0) cur ++;
			cur ++;
		}
		cout << MAX - cur + 1 << '\n';
	}
}

namespace ac {
	const int N = 5e3;
	int dp[N + 3][N + 3];
	void solve() {
		cin >> s1 >> s2;
		int n1 = s1.size(), n2 = s2.size(); s1 = ' ' + s1, s2 = ' ' + s2;
		for (int i = 0; i <= n1; i++)
		for (int j = 0; j <= n2; j++) dp[i][j] = MAX + 1;
		dp[0][0] = 0;
		for (int i = 0; i <= n1; i++)
		for (int j = 0; j <= n2; j++) {
			int cur = dp[i][j] + 1;
			char c;
			if (i < n1) {
				c = s1[i + 1];
				if (c == 'B' && cur % 2 == 1) cur ++;
				if (c == 'R' && cur % 2 == 0) cur ++;
				dp[i + 1][j] = min(dp[i + 1][j], cur);
			}
			cur = dp[i][j] + 1;
			if (j < n2) {
				c = s2[j + 1];
				if (c == 'B' && cur % 2 == 1) cur ++;
				if (c == 'R' && cur % 2 == 0) cur ++;
				dp[i][j + 1] = min(dp[i][j + 1], cur);
			}
		}
		cout << MAX - dp[n1][n2] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	// freopen("b4.inp", "r", stdin);
	// freopen("b4.out", "w", stdout);
	cin >> k;
	if (sub1::check()) {
		sub1::solve();
		return 0;
	}
	ac::solve();
	return 0;
}