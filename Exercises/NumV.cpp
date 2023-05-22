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

const string NAME = "numV";
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

int n, m, color[100003];

vector < int > adj[100003];

bool vs[100003];

ll dfs(int u) {
	vs[u] = 1;
	ll ans = 1 + color[u];
	for (auto v : adj[u]) {
		if (color[v] != -1) {
			if (color[v] == color[u]) return 0;
			continue;
		}
		color[v] = !color[u];
		ans = (ans * dfs(v)) % MOD;
	}
	return ans;
}

void dfs2(int u) {
	color[u] = -1;
	vs[u] = 0;
	for (auto v : adj[u]) if (vs[v]) dfs2(v);
	
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		vs[i] = false;
		color[i] = -1;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll res = 1;
	for (int i = 1; i <= n; i++) {
		if (!vs[i]) {
			ll tam = 0;
			color[i] = 1;
			tam += dfs(i);
			dfs2(i);
			color[i] = 0;
			tam += dfs(i);
			tam %= MOD;
			res = (res * tam) % MOD;
			if (res == 0) {
				cout << res << '\n';
				return ;
			}
		}
	}
	cout << res << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
