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

int n, m, num[150003], low[150003], timer = 0, scc = 0, id_scc[150003], f[150003], g[150003], val[150003];

bool deleted[150003];

int vs[150003];

pii edges[300003];

vector < int > adj[150003], val_scc[150003], adj_scc[150003], adj_scc_rev[150003], topo, res;

stack < int > st;

void dfs(int u) {
	num[u] = low[u] = ++timer;
	st.push(u);
	for (auto v : adj[u]) {
		if(deleted[v]) continue;
		if(!num[v]){
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (num[u] == low[u]) {
		scc ++;
		while (st.top() != u) {
			deleted[st.top()] = true;
			id_scc[st.top()] = scc;
			val_scc[scc].push_back(st.top());
			st.pop();
		}
		deleted[st.top()] = true;
		id_scc[st.top()] = scc;
		val_scc[scc].push_back(st.top());
		st.pop();
	}
}

void dfs_topo(int u) {
	vs[u] = 1;
	for (auto v : adj_scc[u]) {
		if (vs[v] == 0) dfs_topo(v);
	}
	topo.push_back(u);
	vs[u] = 2;
}

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		edges[i] = {u, v};
	}
	for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
	for (int i = 1; i <= m; i++) {
		int u = edges[i].fi, v = edges[i].se;
		if (id_scc[u] != id_scc[v]) {
			adj_scc[id_scc[u]].push_back(id_scc[v]);
			adj_scc_rev[id_scc[v]].push_back(id_scc[u]);
		}
	}
	for (int i = 1; i <= scc; i++) if (vs[i] == 0) dfs_topo(i);
	reverse(topo.begin(), topo.end());
	for (int i = 0; i < topo.size(); i++) val[topo[i]] = i;
	for (int i = 1; i <= scc; i++) {
		sort(adj_scc[i].begin(), adj_scc[i].end(), [&](int &x, int &y) {
			return val[x] < val[y];
		});
		sort(adj_scc_rev[i].begin(), adj_scc_rev[i].end(), [&](int &x, int &y) {
			return val[x] < val[y];
		});
	}
	if (adj_scc[topo[0]].size() != 0) f[0] = val[adj_scc[topo[0]][0]];
	else f[0] = INF;
	for (int i = 1; i < topo.size(); i++) {
		f[i] = f[i - 1];
		if (adj_scc[topo[i]].size()) f[i] = max(f[i], val[adj_scc[topo[i]][0]]);
		else f[i] = INF;
 	}
	if (adj_scc_rev[topo.back()].size()) g[topo.size() - 1] = val[adj_scc_rev[topo.back()].back()];
	else g[topo.size() - 1] = -INF;
	for (int i = topo.size() - 2; i >= 0; i--) {
		g[i] = g[i + 1];
		if (adj_scc_rev[topo[i]].size()) g[i] = min(g[i], val[adj_scc_rev[topo[i]].back()]);
		else g[i] = -INF;
	}
	for (int i = 0; i < topo.size(); i++) {
		bool th = false;
		if (i == 0 && g[i + 1] >= i) th = 1;
		if (i == topo.size() - 1 && f[i - 1] <= i) th = 1;
		if (i != 0 && i != topo.size() - 1) th = (f[i - 1] <= i) && (g[i + 1] >= i);
		if (th) for (auto x : val_scc[topo[i]]) res.push_back(x);
 	}
 	cout << res.size() << '\n';
 	sort(res.begin(), res.end());
 	for (auto x : res) cout << x << " ";
}