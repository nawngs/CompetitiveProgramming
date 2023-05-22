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

int n, m, q, cnt_child[50003], par[50003];

vector < int > adj[50003];

bool used[50003], in_set[50003];

unordered_map < int, int > d[50003];

map < int, int > ans[50003];

int dfs(int u, int e = 0) {
	cnt_child[u] = 1;
	for (auto v : adj[u]) {
		if (used[v] || v == e) continue;
		cnt_child[u] += dfs(v, u);
	}
	return cnt_child[u];
}

void dfs2(int C, int u, int e, int len) {
	d[C][u] = len;
	for (auto v : adj[u]) {
		if (used[v] || v == e) continue;
		dfs2(C, v, u, len + 1);
	}
}

int get_centroid(int u, int ms, int e = 0) {
	for (auto v : adj[u]) {
		if (used[v] || v == e) continue;
		if (cnt_child[v] * 2 > ms) return get_centroid(v, ms, u);
	}
	return u;
}

void centroid(int u = 1, int e = 0) {
	int C = get_centroid(u, dfs(u));
	dfs2(C, C, 0, 0);
	used[C] = 1;
	par[C] = e;
	for (auto v : adj[C]) 
		if (!used[v]) centroid(v, C);
}

void update(int u, int val) {
	for (int v = u; v != 0; v = par[v]) {
		ans[v][d[v][u]] += val;
		if (ans[v][d[v][u]] == 0) ans[v].erase(d[v][u]);
	}
}

pii query(int u) {
	pii res = {INF, 0};
	for (int v = u; v != 0; v = par[v]) {
		if (!ans[v].size()) continue;
		if (res.fi > ans[v].begin()->fi + d[v][u]) {
			res = *ans[v].begin();
			res.fi += d[v][u];
		}
		else if (res.fi == ans[v].begin()->fi + d[v][u]) res.se += ans[v].begin()->se;
	}
	return res;
}

int main() {
	fast;
	cin >> n >> m >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid();
	while (m--) {
		int x;
		cin >> x;
		update(x, 1);
		in_set[x] = 1;
	}
	while (q--) {
		int t, u;
		cin >> t >> u;
		if (t == 1) {
			update(u, (in_set[u] ? -1 : 1));
			in_set[u] = !in_set[u];
		}
		else {
			pii res = query(u);
			cout << res.fi << " " << res.se << '\n';
		}
	}
}
