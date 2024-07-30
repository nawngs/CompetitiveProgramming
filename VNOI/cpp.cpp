#include <bits/stdc++.h>

using namespace std;

int n;

string s;

namespace sub1 {
	int res = 0;
	bool check() { // ham kiem tra co thoa man sub 1
		if (n <= 100) return true;
		else return false;
	}	
	void solve() { // ham xu li sub 1
		for (int l = 0; l < n; l++)
		for (int r = l; r < n; r++) {
			bool ok = 1;
			for (int i = l; i <= r; i++) if (s[i] != s[r - (i - l)]) ok = false;
			if (ok) res ++;
		}
		cout << res << '\n';
	}
}

namespace sub2 {
	int res = 0;
	bool dp[1003][1003];
	bool check() {	// ham kiem tra co thoa man sub 2
		if (n <= 1000) return true;
		else return false;
	}
	void solve() { // ham xu li sub 2
		for (int i = 0; i < n; i++) dp[i][i] = 1, res ++;
		for (int len = 2; len <= n; len++)
		for (int l = 0; l + len - 1 < n; l++) {
			int r = l + len - 1;
			if (s[l] == s[r]) dp[l][r] = dp[l + 1][r - 1];
			else dp[l][r] = 0;
			if (dp[l][r]) res ++;
		}
		cout << res << '\n';
	}
}

int main() {
	cin >> n >> s;
	if (sub1::check()) {
		sub1::solve();
		return 0;
	}
	if (sub2::check()) {
		sub2::solve();
		return 0;
	}
}

