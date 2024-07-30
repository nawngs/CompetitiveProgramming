//[UNFINISHED]
#include <bits/stdc++.h>

#define name "tree-distance"
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
const int NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k, h[NMAX + 3];

ll res = 0;

vector < int > adj[NMAX + 3];

set < pii > ms[NMAX + 3];

void dfs(int u, int e) {
	h[u] = h[e] + 1;
	for (auto v : adj[u]) if (v != e) dfs(v, u);
	ms[u].insert({h[u], 1});
	for (auto v : adj[u]) if (v != e) {
		if (SZE(ms[u]) < SZE(ms[v])) swap(ms[u], ms[v]);
		for (auto x : ms[v]) {
			auto it = ms[u].lower_bound(mp(2 * h[u] + k - x.fi, 0));
			if (it != ms[u].end() && it->fi == 2 * h[u] + k - x.fi) res += 1ll * x.se * 1ll * it->se;
		}
		while(!ms[v].empty()) {
			pii x = *ms[v].begin(); ms[v].erase(x);
			auto it = ms[u].lower_bound(mp(x.fi, 0));
			if (it != ms[u].end() && it->fi == x.fi) {
				x.se += it->se;
				ms[u].erase(it);
			}
			ms[u].insert(x);
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
	cin >> n >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	cout << res;
}