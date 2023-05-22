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

struct Edge {
	int u, v, c;
	bool operator < (Edge const &x) {
		return c < x.c;
	}
} e[100003];

int n, m, q, x, root[100003], sze[100003], res[100003], val1[100003], val2[100003];

set < int > building[100003], query1[100003];

set < pii > query2[100003];

int find_root(int u) {
	return (u == root[u] ? u : root[u] = find_root(root[u]));
}

void merge(int u, int v, int crowd) {
	u = find_root(u);
	v = find_root(v);
	if (u == v) return ;
	if (sze[u] < sze[v]) swap(u, v);
	root[v] = u; sze[u] += sze[v];
	if (building[v].size() > building[u].size()) swap(building[v], building[u]);
	if (query1[v].size() > query1[u].size()) swap(query1[u], query1[v]);
	if (query2[v].size() > query2[u].size()) swap(query2[u], query2[v]);
	for (auto x : building[v]) building[u].insert(x);
	for (auto x : query2[v]) query2[u].insert(x);
	int temp = building[u].size();
	while (query2[u].size() && query2[u].begin()->fi <= temp) {
		val2[query2[u].begin()->se] = crowd;
		query2[u].erase(query2[u].begin());
	}
	while (query1[v].size()) {
		int id = *query1[v].begin();
		if (query1[u].find(id) != query1[u].end()) {
			val1[id] = crowd;
			query1[u].erase(query1[u].find(id));
			query1[v].erase(query1[v].begin());
			continue;
		}
		query1[u].insert(id);
		query1[v].erase(query1[v].begin());
	}
}

int main() {
	fast;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		building[i].insert(t);
		root[i] = i;
		sze[i] = 1;
	}
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].c;
	sort(e + 1, e + m + 1);
	memset(res, 255, sizeof(res));
	for (int i = 1; i <= q; i++) {
		int u, v, k;
		cin >> u >> v >> k;
		if (k <= 1 && u == v) {
			res[i] = 0;
			continue;
		}
		query2[u].insert(make_pair(k, i));
		if (u != v) {
			query1[u].insert(i);
			query1[v].insert(i);
		}
		else val1[i] = 1;
	}
	for (int i = 1; i <= m; i++) merge(e[i].u, e[i].v, e[i].c);
	for (int i = 1; i <= q; i++) {
		if (res[i] != -1) cout << res[i] << '\n';
		else if (val1[i] != 0 && val2[i] != 0) cout << max(val1[i], val2[i]) << '\n';
		else cout << -1 << '\n';
	}
}
