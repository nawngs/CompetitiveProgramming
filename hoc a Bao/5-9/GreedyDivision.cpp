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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[103], dp[103][10003][103], frac[103];

int main() {
	fast;
	cin >> n;
	ll s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
	if (s % 2 == 1) {
		cout << 0 << '\n';
		return 0;
	}
	frac[0] = 1;
	for (int i = 1; i <= n; i++) frac[i] = (frac[i - 1] * i) % MOD;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			for (int k = 0; k <= n; k++) {
				if (dp[i][j][k] == 0) continue;
				dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % MOD;
				if (j + a[i + 1] <= s) 
					dp[i + 1][j + a[i + 1]][k + 1] = (dp[i + 1][j + a[i + 1]][k + 1] + dp[i][j][k]) % MOD; 
			}
		}
	}
	ll res = 0;
	for (int k = 1; k < n; k++) res = (res + dp[n][s / 2][k] * ((frac[k] * frac[n - k]) % MOD)) % MOD;
	cout << res;
}