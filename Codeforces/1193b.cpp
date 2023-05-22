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
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, k, w[100003], d[100003];

vector < int > adj[100003];

map < int, ll > dfs(int u) {
	map < int, ll > ans, temp;
	for (auto v : adj[u]) {
		temp = dfs(v);
		if (sz(temp) > sz(ans))
			swap(ans, temp);
		for (auto x : temp) ans[x.fi] += x.se;
	}
	if (d[u] != -1) {
		ll val = w[u];
		for (auto &x : ans) {
			if (x.fi <= d[u]) continue;
			if (x.se <= w[u]) {
				w[u] -= x.se;
				x.se = 0;
			}
			else {
				x.se -= w[u];
				break;
			}
		}
		ans[d[u]] += val;
	}
	// cout << u << '\n';
	// for (auto x : ans) cout << x.fi << " " << x.se << '\n';
	return ans;
}

main() {
	fast;
	if(fopen(test".inp", "r")) {
		freopen(test".inp", "r", stdin);
		freopen(test".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[p].pb(i);
	}
	memset(d, 255, sizeof(d));
	for (int i = 1; i <= m; i++) {
		int u; cin >> u;
		cin >> d[u] >> w[u];
	}
	map < int, ll > res = dfs(1);
	ll ans = 0;
	for (auto x : res) ans += x.se;
	cout << ans;
}