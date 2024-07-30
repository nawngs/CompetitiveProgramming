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
const int NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, q, a[NMAX + 3], par[NMAX + 3], s1[NMAX + 3], s2[NMAX + 3], s[NMAX + 3], s3[NMAX + 3];

vector < int > adj[NMAX + 3];

void dfs(int u) {
	for (auto v : adj[u]) if (v != par[u]) {
		par[v] = u;
		dfs(v);
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
		s[u] += a[v]; s[v] += a[u];
	}
	dfs(1);
	while (q--) {
		int t, u; cin >> t >> u;
		if (t == 1) {
			ll x; cin >> x;
			s1[u] += x;
			s2[par[u]] += x;
			s3[par[par[u]]] += x;
		}
		else {
			ll res = s[u];
			res += s1[u] * 2 + s2[u] + s1[par[u]]; // tai u
			res += s1[u] * (adj[u].size() - 1) + 2 * s2[u] + s3[u]; // cac thang con u
			res += s2[par[u]] + s1[par[u]] * 2 + s1[par[par[u]]]; // tai cha u
			cout << res << '\n';
		}
	}
}