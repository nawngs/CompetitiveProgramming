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

ll n, a[200003], sum[200003], f[200003], res = 0;

vector < int > adj[200003];

void dfs(int u, int e) {
	sum[u] = a[u];
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		sum[u] += sum[v];
		f[u] += f[v] + sum[v];
	}
}

void dfs2(int u, int e) {
	res = max(res, f[u]);
	for (auto v : adj[u]) {
		if (v == e) continue;
		sum[u] -= sum[v];
		f[u] -= f[v] + sum[v];
		sum[v] += sum[u];
		f[v] += f[u] + sum[u];
		dfs2(v, u);
		sum[v] -= sum[u];
		f[v] -= f[u] + sum[u];
		sum[u] += sum[v];
		f[u] += f[v] + sum[v];
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	dfs(1, 0);
	dfs2(1, 0);
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
