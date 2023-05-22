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

	ll n, m, dp[(1 << 15)][15];

	bool adj[15][15];

	int main() {
		fast;
		if(fopen(name".inp", "r")) {
			freopen(name".inp", "r", stdin);
			freopen(name".out", "w", stdout);
		}
		//int t; cin >> t; while (t --) sol();
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			ll u, v; cin >> u >> v; u--; v --;
			adj[u][v] = 1; adj[v][u] = 1;
		}
		memset(dp, 60, sizeof(dp));
		for (int i = 0; i < n; i++)
			dp[(1 << i)][i] = 0;
		for (int msk = 0; msk < (1 << n); msk++) 
			for (int t = 1; t <= n; t++) {
				for (int lst = 0; lst < n; lst++) if (msk >> lst & 1) {
					for (int nxt = 0; nxt < n; nxt++) if (adj[lst][nxt]) {
						dp[msk | (1 << nxt)][nxt] = min(dp[msk | (1 << nxt)][nxt], dp[msk][lst] + 1);
					}
				}
			}
		ll res = LINF;
		for (int lst = 0; lst < n; lst++) 
			res = min(res, dp[(1 << n) - 1][lst]);
		cout << res;

	}