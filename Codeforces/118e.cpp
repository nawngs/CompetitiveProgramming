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

int n, m, num[100003], low[100003], timeDFS = 0;

vector < int > adj[100003];

map < pii, int > f;

void dfs_bridge(int u, int e) {
	num[u] = low[u] = ++timeDFS;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (!num[v]) {
			dfs_bridge(v, u);
			low[u] = min(low[u], low[v]);
			if (num[v] == low[v]) {
				cout << 0;
				exit(0);
			}
		}
		else low[u] = min(low[u], num[v]);
	}
}

void dfs(int u, int e) {
	num[u] = 1;
	for (auto v : adj[u]) {
		if (!num[v]) {
			cout << u << " " << v << '\n';
			f[{u, v}] = f[{v, u}] = 1;
			dfs(v, u);
		}
		else {
			if (f[{u, v}] == 0) {
				cout << u << " " << v << '\n';
				f[{u, v}] = f[{v, u}] = 1;
			}
		}
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
	dfs_bridge(1, 0);
	memset(num, 0, sizeof(num));
	dfs(1, 0);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
