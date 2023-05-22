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
const ll MOD = 111539786;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string s;

ll k, nxt[1003][2], n, dp[1003][1003];

int calc(int k) {
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++) dp[i][j] = 0;
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++) {
			//cout << i << " " << j << " " << nxt[i + 1][0] << " " << nxt[i + 1][1] << " " << dp[i][j] << '\n';	
			dp[i][j] %= MOD;
			if (nxt[i + 1][0] <= n && j < k) dp[nxt[i + 1][0]][j + 1] += dp[i][j];
			if (nxt[i + 1][1] <= n && j > 0) dp[nxt[i + 1][1]][j - 1] += dp[i][j]; 
		}
	ll res = 0;
	for (int i = 1; i <= n; i++) res += dp[i][0];
	return res % MOD;
}

int main() {
	fast;
	cin >> s >> k;
	n = s.size();
	s = ' ' + s;
	nxt[n + 1][1] = nxt[n + 1][0] = n + 1;
	for (int i = n; i >= 1; i--) {
		nxt[i][0] = nxt[i + 1][0];
		nxt[i][1] = nxt[i + 1][1];
		if (s[i] == '(') nxt[i][0] = i;
		else nxt[i][1] = i;
	}
	cout << (calc(k) - calc(k - 1) + 2 * MOD) % MOD;
}
