#pragma GCC optimize ("O3")
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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

//#######################################################################
// data
struct Edges {
	int v, c, index;
	Edges (int _v, int _c, int _index) : v(_v), c(_c), index(_index) {};
};

int n, log2_n;

vector < Edges > adj[10005];

//#######################################################################
// dfs + LCA
int p[10005][15], h[10005], cnt_child[10005];
void dfs(int u) {
	cnt_child[u] = 1;
	h[u] = h[p[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v.v == p[u][0]) continue;
		p[v.v][0] = u;
		dfs(v.v);
		cnt_child[u] += cnt_child[v];
	}
}

void init_LCA() {

	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= log2_n; j++) p[i][j] = 0;

	for (int j = 1; j <= log2_n; j++)
		for (int i = 1; i <= n; i++) p[i][j] = p[p[i][j - 1]][j - 1];
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) for (int j = log2_n; j >= 0; j--) if (h[p[v][j]] >= h[u]) v = p[v][j];
	if (u == v) return u;
	for (int j = log2_n; j >= 0; j--) {
		if (p[u][j] != 0 && p[u][j] != p[v][j]) {
			u = p[u][j];
			v = p[v][j];
		}
	}
	return p[u][0];
}

//#######################################################################
//hld
int chain_ind[10005], chain_head[10005], 

//#######################################################################
// solution

void sol() {
	cin >> n;
	log2_n = log2(n) + 1;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c, i});
		adj[v].push_back({u, c, i});
	}
	dfs(1);
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
