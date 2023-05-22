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
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int BLOCK_SIZE = 450;

int n, m, par[NMAX + 3], Id[NMAX + 3], res[BLOCK_SIZE + 3][NMAX + 3];

bool vs[NMAX + 3];

vector < vector < int > > comps;

vector < pii > edges[NMAX + 3];

vector < int > tree[NMAX + 3], InComp[NMAX + 3];

int find(int u) {
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

bool join(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	par[v] = u;
	return true;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		edges[c].push_back(mp(u, v));
	}
	for (int i = 1; i <= n; i++) 
		par[i] = i, vs[i] = 0;
	for (int i = 1; i <= NMAX; i++) {
		for (auto e : edges[i]) {
			int u, v; tie(u, v) = e;
			join(u, v);
		}
		for (auto e : edges[i]) {
			int u, v; tie(u, v) = e;
			if (!vs[u]) {
				tree[find(u)].push_back(u);
				vs[u] = 1;
			}
			if (!vs[v]) {
				tree[find(v)].push_back(v);
				vs[v] = 1;
			}
		}
		for (auto e : edges[i]) {
			int u, v; tie(u, v) = e;
			if (sz(tree[u])) comps.push_back(tree[u]), tree[u].clear();
			if (sz(tree[v])) comps.push_back(tree[v]), tree[v].clear();
			vs[u] = vs[v] = false;
			par[u] = u; par[v] = v;
		}
	}
	for (int i = 0; i < sz(comps); i++) 
		for (auto x : comps[i]) 
			InComp[x].push_back(i);
	vector < int > BigVertex;
	memset(Id, 255, sizeof(Id));
	for (int i = 1; i <= n; i++) 
		if (InComp[i].size() > BLOCK_SIZE) {
			Id[i] = sz(BigVertex);
			BigVertex.push_back(i);
		}
	for (int i = 0; i < sz(BigVertex); i++) {
		int u = BigVertex[i];
		for (auto C : InComp[u])
			for (auto v : comps[C]) res[i][v] ++;
	}
	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		if (Id[u] == -1) 
			swap(u, v);
		if (Id[u] != -1) 
			cout << res[Id[u]][v] << '\n';
		else {
			int curu = 0, curv = 0, res = 0;
			while (curu < sz(InComp[u]) && curv < sz(InComp[v])) {
				if (InComp[u][curu] == InComp[v][curv]) res ++, curu++, curv++;
				else if (InComp[u][curu] > InComp[v][curv]) curv++;
				else curu++;
			}
			cout << res << '\n';
		}
	}
}