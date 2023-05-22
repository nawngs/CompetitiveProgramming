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
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll fac[5003], n, k, dp[5003], inv[5003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return (fac[n] * inv[k] % MOD * inv[n - k]) % MOD;
}


int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % MOD;
	for (int i = 0; i <= n; i++) 
		inv[i] = mu(fac[i], MOD - 2);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) 
		for (int p = 1; p < i; p++) if (p * (n - p) <= k) 
			dp[i] = (dp[i] + C(p - 1, i - 2) * dp[p] % MOD * p % MOD * dp[i - p] % MOD) % MOD;
		
	cout << dp[n];
}