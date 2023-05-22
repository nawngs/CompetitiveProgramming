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

const string NAME = "virus";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, dp[3003][3003], f[3003][3003];

string s;

int main() {
	fast;
	fre();
	int t; cin >> t;
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) 
		dp[i][n] = (s[i] == s[n]);
	for (int i = n - 1; i >= 1; i--) 
		for (int j = n - 1; j >= 1; j--) 
			dp[i][j] = dp[i + 1][j + 1] + (s[i] == s[j]);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			f[i][j] = -1;
			if (j + (j - i + 1) > n) continue;
			f[i][j] = dp[i][j + 1] - dp[j + 1][j + 1 + (j - i + 1)];
		}
	while (t--) {
		int k; cin >> k;
		int res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++) {
				if (f[i][j] == -1) continue;
				if (j - i + 1 - f[i][j] <= k) res = max(res, j - i + 1);
			}
		cout << res << '\n';	
	}
}
