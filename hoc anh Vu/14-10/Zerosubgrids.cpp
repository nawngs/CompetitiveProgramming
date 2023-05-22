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
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[4][300003], nxt[4][300003], s[300003];

map < ll, int > f;

pll dp[4][300003];

void maximize(pll &x, pll y) {
	if (x.fi < y.fi) x = y;
	else if (x.fi == y.fi) x.se = min(x.se, y.se);
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			a[3][j] = a[1][j] + a[2][j];
		}
	for (int i = 1; i <= 3; i++) {
		s[n + 1] = 0;
		f.clear();
		f[0] = n + 1;
		nxt[i][n + 1] = n + 2;
		for (int j = n; j >= 1; j--) {
			s[j] = s[j + 1] + a[i][j];
			nxt[i][j] = nxt[i][j + 1];
			if (f.find(s[j]) != f.end()) 
				nxt[i][j] = min(nxt[i][j], 1ll * f[s[j]]);
			f[s[j]] = j;
		}
	}
	for (int i = 1; i <= 2; i++)
		for (int j = 0; j <= n; j++) dp[i][j] = {-1, -1};
	dp[1][0] = {0, 0};
	dp[2][0] = {0, 0};
	ll res = 0;
	for (int j = 0; j <= n; j++) {
		for (int i = 1; i <= 2; i++) {
			if (dp[i][j].fi == -1) continue;
			//cout << i << " " << j << " " << dp[i][j].fi << " " << dp[i][j].se << " " << nxt[3][j + 1] - 1 << '\n';
			res = max(res, dp[i][j].fi);
			if (nxt[i][j + 1] - 1 <= n) 
				maximize(dp[i][nxt[i][j + 1] - 1], {dp[i][j].fi + 1, dp[i][j].se});
			if (nxt[3 - i][dp[i][j].se + 1] - 1 <= n) 
				maximize(dp[3 - i][nxt[3 - i][dp[i][j].se + 1] - 1], {dp[i][j].fi + 1, j});
			if (nxt[3][j + 1] - 1 <= n) {
				maximize(dp[1][nxt[3][j + 1] - 1], {dp[i][j].fi + 1, nxt[3][j + 1] - 1});
				maximize(dp[2][nxt[3][j + 1] - 1], {dp[i][j].fi + 1, nxt[3][j + 1] - 1});
			}

		}
	}
	cout << res;
}
