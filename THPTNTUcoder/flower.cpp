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

struct Edge {
	int u, v;
} edges[100003];

int n, m, timeDFS, num[20003], low[20003], dem = 0;

bool visited[20003], check[100003];

vector < pii > adj[20003];
vector < int > adj2[20003];

void dfs1(int u, int e) {
	num[u] = low[u] = ++ timeDFS;
	for (auto v : adj[u]) {
		if (v.se == e) continue;
		if (!num[v.fi]) {
			dfs1(v.fi, v.se);
			low[u] = min(low[u], low[v.fi]);
			if (low[v.fi] == num[v.fi]) check[v.se] = 1;
		}
		else low[u] = min(low[u], num[v.fi]);
	}
}

void dfs2(int u, int e) {
	visited[u] = 1;
	dem += adj2[u].size();
	for (auto v : adj2[u]) {
		if (v == e) continue;
		if (!visited[v]) dfs2(v, u);
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> edges[i].u >> edges[i].v;
		adj[edges[i].u].push_back({edges[i].v, i});
		adj[edges[i].v].push_back({edges[i].u, i});

	}	
	for (int i = 1; i <= n; i++) if (!num[i]) dfs1(i, 0);
	for (int i = 1; i <= m; i++) 
		if (!check[i]) {
			adj2[edges[i].u].push_back(edges[i].v);
			adj2[edges[i].v].push_back(edges[i].u);
		}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dem = 0;
			dfs2(i, 0);
			ans = max(ans, dem / 2);
		}
	}
	cout << (ans == 0 ? m : ans);
}


int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
