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

int n, q, type[100003], xx[100003], yy[100003], par[100003], rnk[100003], res[100003];

vector < pii > it[400003];

map < pii, vector < int > > f;

struct dsu_save {
    int v, rnkv, u, rnku;

    dsu_save() {}

    dsu_save(int _v, int _rnkv, int _u, int _rnku)
        : v(_v), rnkv(_rnkv), u(_u), rnku(_rnku) {}
};

vector < dsu_save > troll[400003];

void update(int node, int l, int r, int u, int v, pii val) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		it[node].push_back(val);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
} 

int find(int u) {
	return par[u] == u ? u : find(par[u]);
}

void merge(int u, int v, int id) {
	u = find(u); v = find(v);
	if (u == v) return ;
	if (rnk[v] > rnk[u]) swap(u, v);
	troll[id].push_back({v, rnk[v], u, rnk[u]});
	par[v] = u;
	if (rnk[u] == rnk[v]) rnk[u] ++;
	return ;
}

void dfs(int node, int l, int r) {
	for (auto e : it[node]) 
		merge(e.fi, e.se, node);
	if (l != r) {
		int mid = (l + r) / 2;
		dfs(node * 2, l, mid);
		dfs(node * 2 + 1, mid + 1, r);
	}
	else {
		if (type[l] == 3) 
			res[l] = (find(xx[l]) == find(yy[l]));
	}
	for (auto u : troll[node]) {
		rnk[u.v] = u.rnkv;
		rnk[u.u] = u.rnku;
		par[u.v] = u.v;
	}
}

int main() {
	fast;
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		cin >> type[i] >> xx[i] >> yy[i];
		if (xx[i] > yy[i]) swap(xx[i], yy[i]);
	}
	for (int i = 1; i <= q; i++) {
		if (type[i] == 1) f[{xx[i], yy[i]}].push_back(i);
		if (type[i] == 2) {
			if (!f[{xx[i], yy[i]}].size()) continue;
			update(1, 1, q, f[{xx[i], yy[i]}].back(), i - 1, {xx[i], yy[i]});
			f[{xx[i], yy[i]}].pop_back();
		}
	}
	for (auto x : f) 
		if (x.se.size()) 
			update(1, 1, q, x.se[0], q, x.fi);
	for (int i = 1; i <= n; i++) 
		par[i] = i, rnk[i] = 0;
	dfs(1, 1, q);
	for (int i = 1; i <= q; i++) 
		if (type[i] == 3) cout << res[i];
}
