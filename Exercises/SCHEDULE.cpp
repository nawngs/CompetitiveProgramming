#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "schedule";
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

int n, m, t[100003], res[100003], len;

bool vs[100003];

vector < int > adj[100003], adj_rev[100003], topo;

void dfs(int u) {
	vs[u] = 1;
	for (auto v : adj[u]) {
		if (vs[v]) continue;
		dfs(v);
	}
	topo.push_back(u);
}

main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_rev[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) 
		if (!vs[i]) dfs(i);
	reverse(topo.begin(), topo.end());
	for (auto x : topo) {
		int &val = res[x];
		val = 1;
		for (auto v : adj_rev[x]) val = max(val, res[v] + t[v]);
		len = max(len, res[x] + t[x] - 1);
	}
	cout << len << '\n';
	for (int i = 1; i <= n; i++) 
		cout << res[i] << '\n';
}
