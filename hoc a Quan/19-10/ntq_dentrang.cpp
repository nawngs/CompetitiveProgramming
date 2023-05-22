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

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const int INF = 1e9 + 7;
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

int n, par[100003], Head, Tail, ance[100003], f[100003][2][2][2][2];

vector < int > adj[100003];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

void dfs(int u, int e) {
	for (auto v : adj[u]) {
		if (v == e) continue;
		ance[v] = u;
		dfs(v, u);
	}
}

int dfs(int u, int cur, int up, int H, int T) {
	if (f[u][cur][up][H][T] != -1)
		return f[u][cur][up][H][T];
	int &res = f[u][cur][up][H][T];
	res = INF;
	bool valid = 1;
	if (u == Head && cur != H) 
		return res;
	if (u == Tail && cur != T) 
		return res;
	if (u == Tail && up && H) 
		return res;
	int add = cur;
	for (auto v : adj[u]) {
		if (v == ance[u]) continue;
		add += dfs(v, 0, cur, H, T);
	}
	valid = 1;
	if (up) valid = 0;
	if (u == Tail && H) valid = 0;
	if (u == Head && T) valid = 0;
	if (!valid) res = min(res, add);
	else {
		for (auto v : adj[u]) {
			if (v == ance[u]) continue;
			res = min(res, add - dfs(v, 0, cur, H, T) + dfs(v, 1, cur, H, T));
		}
	}
	return res;
}

main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++)
		par[i] = i;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		int root_u = find(u);
		int root_v = find(v);
		if (root_u == root_v) Head = u, Tail = v;
		else {
			par[root_v] = root_u;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	dfs(Head, 0);
	memset(f, 255, sizeof(f));
	int res = INF;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) 
			res = min(res, dfs(Head, i, 0, i, j));
	cout << (res >= INF ? -1 : res);
}
