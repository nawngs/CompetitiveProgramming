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

const string NAME = "line";
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

ll n, k, cnt[200003], height[200003];

int dp[200003][303];

ll frac[400003], inv[400003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll Ckn(ll k, ll n) {
	return ((frac[n] * inv[k]) % MOD * inv[n - k]) % MOD;
}

ll chiakeo(ll n, ll m) {
	return Ckn(n, m + n - 1);
}

int main() {
	fast;
	//fre();
	int O; cin >> O;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		cnt[x] ++;
	}
	frac[0] = 1;
	for (int i = 1; i <= 2 * n; i++)
		frac[i] = (frac[i - 1] * i) % MOD;
	inv[2 * n] = mu(frac[2 * n], MOD - 2);
	for (int i = 2 * n - 1; i >= 0; i--) 
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;
	
	n = 0;
	for (int i = nmax; i >= 0; i--) {
		if (cnt[i] == 0) continue;
		height[++ n] = cnt[i];
 	}
 	dp[1][0] = 1;
 	ll total = height[1];
 	for (int i = 1; i < n; i++) {
 		for (int j = 0; j <= min(k, height[i + 1]); j++)
 			for (int p = 0; p + j <= k; p++) {
 				if (dp[i][p] != 0)
 					dp[i + 1][p + j] = (dp[i + 1][p + j] + (1ll * dp[i][p] * chiakeo(j, total) % MOD)) % MOD;
 			}
 		total += height[i + 1];
 	}
 	ll res = 0;
 	for (int i = 0; i <= k; i++) res = (res + dp[n][i]) % MOD;
 	for (int i = 1; i <= n; i++)
 		res = (res * frac[height[i]]) % MOD;
 	cout << res;
}
