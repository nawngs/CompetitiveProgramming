#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

int m, t[5003], dp[5003];

string s;

int main() {
	fast;
	cin >> m >> s;
	int n = s.size();
	s = ' ' + s;
	m -= n;
	t[1] = 0;
	for (int i = 2; i <= n; i++) {
		int k = t[i - 1];
		while (k > 0 && s[k + 1] != s[i]) k = t[k];
		if (s[k + 1] == s[i]) t[i] = k + 1;
		else t[i] = 0; 
	}
	dp[0] = 1;
	for (int i = 0; i < m; i++) {
		for(int k = 1; k <= min(m - i, n); k++) {
			if (t[k] == 0) dp[i + k] = (dp[i + k] + dp[i]) % MOD;
		}
	}
	cout << dp[m];
}
