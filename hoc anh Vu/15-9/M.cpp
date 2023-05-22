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

int n, m, par[300003], id[300003], res[300003], dsu[300003], h[300003];

pii edges[300003];

vector < int > adj[300003];

bool mst[300003];

int find_root(int u) {
	return (dsu[u] == u ? u : dsu[u] = find_root(dsu[u]));
}

void dfs(int u) {
	for (auto i : adj[u]) {
		int v = edges[i].fi + edges[i].se - u;
		if (v == par[u]) continue;
		h[v] = h[u] + 1;
		par[v] = u;
		id[v] = i;
		dfs(v);
	}
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> edges[i].fi >> edges[i].se;
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		mst[x] = 1;
		adj[edges[x].fi].push_back(x);
		adj[edges[x].se].push_back(x);
	}
	for (int i = 1; i <= n; i++) dsu[i] = i;
	dfs(1);
	int cur = 0;
	for (int i = 1; i <= m; i++) {
		if (res[i] != 0) continue;
		if (mst[i]) res[i] = ++ cur;
		else {
			vector < int > tmp;
			int u = edges[i].fi, v = edges[i].se;
			u = find_root(u);
			v = find_root(v);
			while (u != v) {
				if (h[u] < h[v]) swap(u, v);
				tmp.push_back(id[u]);
				dsu[u] = par[u];
				u = find_root(u);
			}
			sort (tmp.begin(), tmp.end());
			for (auto x : tmp) if (res[x] == 0) res[x] = ++ cur;
			res[i] = ++ cur;
		}
	}
	for (int i = 1; i <= m; i++) cout << res[i] << " ";
}
