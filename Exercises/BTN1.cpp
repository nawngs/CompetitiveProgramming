#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

int dp[705][705];

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("BTN1.inp", "r", stdin);
	freopen("BTN1.out", "w", stdout);
	cin >> s;
	ll n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dp[i][j] = -1e9;
		}
	}
	for (int k = 2; k <= n; k += 2) {
		for (int i = 1; i <= n - k + 1; i++) {
			int j = (i + k) - 1;
			for (int p = i + 1; p < j; p += 2) if (dp[i][p] > 0 && dp[p + 1][j] > 0) dp[i][j] = max(dp[i][j], max(dp[i][p], dp[p + 1][j]));	
			if (s[i] == ')' || s[j] == '(') continue;
			dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
		}
	}
	cout << dp[1][n];
}
