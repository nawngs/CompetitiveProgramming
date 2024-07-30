#include <bits/stdc++.h>

#define int ll
#define ll long long
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fi first
#define se second
#define pb push_back
#define SIZ(x) (int)(x.size())
#define mp make_pair

using namespace std;

const int NMAX = 1E5;
const int LG = 17;

struct Edge {
	int u, v, c;
} edges[NMAX + 3];

int n, s[NMAX + 3], q, in[NMAX + 3];

map < pii, int > ID;

map < vector < int >, bool > finded;

vector < int > canh[2][NMAX + 3];

pii connect[NMAX + 3];

vector < pll > adj[NMAX + 3];

void update(int u, int v, const int &val) {
	if (u > v) swap(u, v);
	if (ID[mp(u, v)] == 0) {
		if (u == 1 && v == n) in[v] = val;
		else in[u] = val;
	}
	else {
		if (connect[ID[{u, v}]].fi == -1) connect[ID[{u, v}]].fi = val;
		else connect[ID[{u, v}]].se =  val;
	}
}

ll h[NMAX + 3], par[NMAX + 3][LG + 3], val[NMAX + 3][LG + 3];

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	for (int i = 1; i <= LG; i++) {
		par[u][i] = par[par[u][i - 1]][i - 1];
		val[u][i] = val[u][i - 1] + val[par[u][i - 1]][i - 1];
	}
	for (auto v : adj[u]) {
		if (v.fi == par[u][0]) continue;
		par[v.fi][0] = u; val[v.fi][0] = v.se;
		dfs(v.fi); 
	}
}

ll LCA(int u, int v) {
	ll res = 0;
	if (h[u] < h[v]) swap(u, v);
	for (int i = LG; i >= 0; i--) if (h[par[u][i]] >= h[v]) {
		res += val[u][i];
		u = par[u][i];
	}
	if (u == v) return res;
	for (int i = LG; i >= 0; i--) if (par[u][i] != par[v][i]) {
		res += val[u][i] + val[v][i];
		u = par[u][i], v = par[v][i];
	}
	res += val[u][0] + val[v][0];
	return res;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int u = i, v = (u + 1) % n;
		if (u > v) swap(u, v);
		if (u == 0) u += n;
		if (u > v) swap(u, v);
		canh[1][u].pb(v);
		canh[0][v].pb(u);
		ID[{u, v}] = 0;
	}
	for (int i = 1; i <= n - 3; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].c;
		if (edges[i].u > edges[i].v) swap(edges[i].u, edges[i].v);
		canh[1][edges[i].u].pb(edges[i].v);
		canh[0][edges[i].v].pb(edges[i].u);
		ID[{edges[i].u, edges[i].v}] = i;
		connect[i] = {-1, -1};
	}
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			sort(canh[j][i].begin(), canh[j][i].end());
			for (int p = 1; p < SIZ(canh[j][i]); p++) {
				int u = canh[j][i][p - 1], v = canh[j][i][p];
				if (u > v) swap(u, v);
				if (ID.find({u, v}) == ID.end()) continue;
				vector < int > temp;
				temp.pb(i); temp.pb(u); temp.pb(v);
				sort(temp.begin(), temp.end());
				if (finded.find(temp) != finded.end()) continue;
				finded[temp] = 1;
				cur ++;
				update(i, u, cur); update(i, v, cur); update(u, v, cur);
			}
		}
	}
	for (int i = 1; i <= n - 3; i++) {
		//cout << i << " " << connect[i].fi << " " << connect[i].se << '\n';
		adj[connect[i].fi].pb({connect[i].se, edges[i].c});
		adj[connect[i].se].pb({connect[i].fi, edges[i].c});
	}
	dfs(1);
	while (q--) {
		int u, v; cin >> u >> v;
		cout << LCA(in[u], in[v]) << '\n';
	}
}
