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

ll n, k;

namespace sub1 {
	ll dp[(1 << 16)][16][16];    
	void solve() {
		for (int i = 0; i < n; i++) 
			dp[(1 << i)][i][i] = 1;
		for (int mask = 1; mask < (1 << n); mask++) 
			for (int f = 0; f < n; f++) {
				if (!((mask >> f) & 1)) continue;
				for (int last = 0; last < n; last++) {
					if (dp[mask][f][last] == 0) continue;
					for (int i = 0; i < n; i++) {
						if ((mask >> i) & 1) continue;
						if ((last + 1) % (i + 1) <= k) dp[mask ^ (1 << i)][f][i] += dp[mask][f][last];
					}
				}
			}
		ll res = 0;
		for (int f = 0; f < n; f++)
			for (int last = 0; last < n; last++) 
				if ((last + 1) % (f + 1) <= k) res += dp[(1 << n) - 1][f][last];
		cout << res % MOD << '\n';
		return ;
	}
}

namespace sub2 {
	ll dp[1000003];
	void solve() {
		dp[3] = 1; 
		ll res = 0;
		for (int i = 3; i <= n; i++) {
			res = (res + dp[i]) % MOD;
			dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
			for (int x = 2; (i - 1) * x <= n; x++) {
				for (int y = 0; y <= min(i - 2, 2); y++) {
					if ((i - 1) * x + y > n) break;
					if ((i - 1) * x + y <= i + 1) continue;
					dp[(i - 1) * x + y] = (dp[(i - 1) * x + y] + dp[i]) % MOD; 
				}
			}
		}
		cout << (res * 2 * n) % MOD;
	}
}

int main() {
	fast;
	//fre();
	cin >> n >> k;
	if (k == 1) {
		cout << n << '\n';
		return 0;
	}
	if (n <= 16) 
		sub1::solve();
	else 
		sub2::solve();
}
