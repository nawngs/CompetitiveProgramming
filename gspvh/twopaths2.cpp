#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define name "twopaths"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n;

ll w[NMAX + 3], down[NMAX + 3], up[NMAX + 3], f[NMAX + 3], g[NMAX + 3], res = -LINF;

vector < int > adj[NMAX + 3];

vector < ll > temp1, temp2, temp;

void dfs1(int u, int e) {
	vector < ll >().swap(temp);
	temp.pb(w[u]); temp.pb(w[u]);
	down[u] = w[u];
	for (auto v : adj[u]) if (v != e) {
		dfs1(v, u);
		down[u] = max(down[u], down[v] + w[u]);
		f[u] = max(f[u], f[v]);
		temp.pb(down[v] + w[u]);
	}
	sort(temp.begin(), temp.end());
	f[u] = max(f[u], temp.back() + temp[temp.size() - 2] - w[u]);
}

void dfs2(int u, int e) {
	vector < ll >().swap(temp1);
	vector < ll >().swap(temp2);
	temp2.pb(up[u]);
	for (auto v : adj[u]) if (v != e) {
		g[v] = g[u];
		temp1.pb(f[v]);
		temp2.pb(down[v] + w[u]);
	}
	while (temp1.size() < 2) temp1.push_back(0);
	sort(temp1.begin(), temp1.end());
	while (temp2.size() < 3) temp2.push_back(w[u]);
	sort(temp2.begin(), temp2.end());
	for (auto v : adj[u]) if (v != e) {
		if (f[v] != temp1.back()) g[v] = max(g[v], temp1.back());
		else g[v] = max(g[v], temp1[temp1.size() - 2]);
		ll total = temp2.back() + temp2[temp2.size() - 2] + temp2[temp2.size() - 3];
		if (down[v] + w[u] > temp2[temp2.size() - 3])
			g[v] = max(g[v], total - down[v] - 2 * w[u]);
		else g[v] = max(g[v], total - temp2[temp2.size() - 3] - w[u]);
		if (down[v] + w[u] != temp2.back()) up[v] = max(up[v], temp2.back() + w[v]);
		else up[v] = max(up[v], temp2[temp2.size() - 2] + w[v]);
		dfs2(v, u);
	}
	res = max(res, g[u] + f[u]);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs1(1, 0); dfs2(1, 0);
	cout << res;
}