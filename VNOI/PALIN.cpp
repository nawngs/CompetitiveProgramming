#include <bits/stdc++.h>

using namespace std;

int n, m;

string s, t;

int dp[1003][1003];

int main() {
	cin >> n >> m >> s >> t;
	s = ' ' + s; t = ' ' + t;
	for (int i = 1; i <= n; i++) if (s[i] == t[1]) dp[i][1] = 1;
	for (int j = 1; j <= m; j++) if (s[1] == t[j]) dp[1][j] = 1;
	
	for (int i = 2; i <= n; i++)
	for (int j = 2; j <= m; j++) {
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		if (s[i] == s[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
	}
	cout << dp[n][m];
}

