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

const string NAME = "bridges";
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

int n, m, timeDFS = 0, num[100003], low[100003], bridges = 0;

vector < int > adj[100003];

void dfs(int u, int e) {
	num[u] = low[u] = ++ timeDFS;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (!num[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (num[v] == low[v]) bridges ++;
		}
		else low[u] = min(low[u], num[v]);
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << bridges;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}

