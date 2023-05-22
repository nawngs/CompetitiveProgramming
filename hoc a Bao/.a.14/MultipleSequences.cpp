#include <bits/stdc++.h>

#define name ""
#define test "test"
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

ll n, m, dp[22][200003], frac[200003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return (frac[n] * mu((frac[k] * frac[n - k]) % MOD, MOD - 2)) % MOD;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	ll k = log2(m) + 1;
	k = min(k, n);
	frac[0] = 1;
	for (int i = 1; i <= n; i++) frac[i] = (frac[i - 1] * i) % MOD;
	for (int i = 1; i <= m; i++) dp[1][i] = 1;
	for (int t = 1; t < k; t++) {
		for (int i = 1; i <= m; i++)
			if (dp[t][i] != 0) for (int j = 2 * i; j <= m; j+=i) 
				dp[t + 1][j] = (dp[t + 1][j] + dp[t][i]) % MOD;
	
	}
	ll res = 0;
	for (int t = 1; t <= k; t++) {
		ll total = 0;
		for (int i = 1; i <= m; i++) 
			total = (total + dp[t][i]) % MOD;
		res = (res + total * C(t - 1, n - 1)) % MOD;
	}
	cout << res << '\n';
}
