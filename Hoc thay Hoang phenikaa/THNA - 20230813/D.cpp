//[UNFINISHED]
#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, f[NMAX + 3];

ll dp[NMAX + 3];

vector < int > pos[128], prime[NMAX + 3];

void sieve() {
	for (int i = 1; i <= NMAX; i++) 
		f[i] = i;
	for (int i = 2; i * i <= NMAX; i++) 
		if (f[i] == i) for (int j = 2 * i; j <= NMAX; j+=i) f[j] = i;
	for (int i = 1; i <= NMAX; i++) {
		int pre = -1, delta = i;
		while (delta > 1) {
			if (f[delta] != pre) prime[i].pb(f[delta]);
			pre = f[delta]; delta /= f[delta];
		}
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	sieve();
	cin >> n;
	for (int i = 1; i <= n; i++) dp[i] = 1;
	ll res = 0;
	for (int i = 0; i < 128; i++) 
		for (int j = 0; j < 7; j++) if (i >> j & 1) 
			pos[i].pb(j);
	for (int i = 1; i <= n; i++) {
		res = (res + dp[i]) % MOD;
		// cout << i << " " << dp[i] << '\n';
		for (int j = 2 * i; j <= n; j+=i) {
			int delta = j / i;
			ll total = 0;
			int m = prime[delta].size();
			for (int msk = 0; msk < (1 << m); msk++) {
				int val = i;
				for (auto y : pos[msk]) val *= prime[delta][y];
				if (SZE(pos[msk]) % 2 == 0) total += 1ll * (n / val);
				else total -= 1ll * (n / val);
			}
			dp[j] = (dp[j] + dp[i] * total) % MOD;
		}
	}
	cout << res;
}