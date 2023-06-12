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
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, adj[1003][1003], deg[1003], cur = -1, pos1, pos2, num, res = 0;

bool vs[1003];

pii a[1003];

vector < int > ans[503], adj_2[1003];

void dfs_count(int u) {
	vs[u] = 1;
	if (deg[u] % 2 == 1) {
		if (cur == -1) cur = u;
		else {
			pos1 = u;
			pos2 = cur;
			cur = -1;
			adj[pos1][pos2] |= 2;
			adj[pos2][pos1] |= 2;
			adj_2[pos1].push_back(pos2);
			adj_2[pos2].push_back(pos1);
		}
	}
	for (auto i : adj_2[u]) if (adj[u][i] && !vs[i]) dfs_count(i);
}

void dfs_find_ans(int u, int id) {
	res = max(res, id);
	vs[u] = 1;
	for (auto i : adj_2[u]) {
		if (adj[u][i] & 2) {
			adj[u][i] ^= 2; adj[i][u] ^= 2;
			dfs_find_ans(i, id + 1);
		}
	}
	for (auto i : adj_2[u]) {
		if (adj[u][i]) {
			adj[u][i] = adj[i][u] = 0;
			dfs_find_ans(i, id);
		}
	}
	ans[id].push_back(u);
}

int main() {
	//fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj_2[u].push_back(v);
		adj_2[v].push_back(u);
		adj[u][v] = adj[v][u] = 1;
		deg[u] ++;
		deg[v] ++;
	}
	for (int i = 1; i <= n; i++) if (!vs[i]) {
		pos1 = pos2 = -1;
		dfs_count(i);
		if (pos1 != -1) {
			adj[pos1][pos2] ^= 2;
			adj[pos2][pos1] ^= 2;
			adj_2[pos1].pop_back();
			adj_2[pos2].pop_back();
		}
		a[i] = {pos1, pos2};
	}
	memset(vs, false, sizeof(vs));
	for (int i = 1; i <= n; i++) if (!vs[i]) {
		num = res + 1;
		if (a[i].fi == a[i].se) dfs_find_ans(i, num);
		else dfs_find_ans(a[i].fi, num);			
	}
	cout << res << '\n';
	for (int i = 1; i <= res; i++) {
		cout << ans[i].size() << " ";
		for (auto x : ans[i]) cout << x << " ";
		cout << '\n';
	}
}
