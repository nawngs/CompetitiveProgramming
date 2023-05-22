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

int n, q, Query_d[100003];

ll res[100003];

vector < int > adj[100003], qi[100003];

map < pair < int, int >, int > f[100003];

// first: {truy van, depth}
// se: so dinh

void dfs(int u, int e, int dpt) {
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u, dpt + 1);
		if (f[v].size() > f[u].size()) 
			swap(f[u], f[v]);
		for (auto x : f[v]) {
			ll temp = Query_d[x.fi.fi] + 2 * dpt - x.fi.se;
			res[x.fi.fi] += 1ll * x.se * 1ll * f[u][{x.fi.fi, temp}];
		}
		for (auto x : f[v]) 
			f[u][x.fi] += x.se;

	}
	for (auto x : qi[u]) {
		res[x] += 1ll * f[u][{x, dpt + Query_d[x]}];
		f[u][{x, dpt}] ++;
	}
}

void sol() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		f[i].clear();
		qi[i].clear();
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= q; i++) {
		int k, d; cin >> k >> d;
		Query_d[i] = d;
		res[i] = 0;
		while (k--) {
			int x; cin >> x;
			qi[x].push_back(i);
		}
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
