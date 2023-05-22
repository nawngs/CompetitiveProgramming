#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 998244353;
const ll BASE = 2309;

ll n, s, nk, fac[103], inv[103], pw[103][103];

vector < ll > dp[103];

pll a[103];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	return fac[n] * inv[n - k] % MOD * inv[k] % MOD;
}

int main() {
	fast;
	if (fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> s >> nk;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		pw[i][0] = 1;
		for (int j = 1; j <= nk; j++)
			pw[i][j] = (pw[i][j - 1] * a[i].se) % MOD;
	}
	fac[0] = 1;
	for (int i = 1; i <= nk; i++)
		fac[i] = (fac[i - 1] * i) % MOD;
	for (int i = 0; i <= nk; i++)
		inv[i] = mu(fac[i], MOD - 2);
	for (int j = 0; j <= s; j++)
			dp[j].resize(nk + 3, 0);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) 
		for (int k = s; k >= a[i + 1].fi; k--) 
			for (int j = 0; j <= nk; j++) 
				for (int jj = 0; jj <= j; jj++) 
					dp[k][j] = (dp[k][j] + C(jj, j) * dp[k - a[i + 1].fi][jj] % MOD * pw[i + 1][j - jj]) % MOD;
	ll res = 0;
	for (int i = 0; i <= s; i++)
		res = (res + dp[i][nk]) % MOD;
	cout << res;
}