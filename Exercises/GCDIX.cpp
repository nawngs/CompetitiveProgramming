#include <bits/stdc++.h>

#define pb push_back

using namespace std;

const int N = 1e5;

int n, m, a[N + 3], par[N + 3], h[N + 3];

vector < int > adj[N + 3];

void dfs(int u, int e) {
	par[u] = e; h[u] = h[e] + 1;
	for (auto v : adj[u]) if (v != e) dfs(v, u);
}

void upd(int u, int v, int x) {
	while (h[u] > h[v]) {
		a[u] += x;
		u = par[u];
	}
	while (h[v] > h[u]) {
		a[v] += x;
		v = par[v];
	}
	while (u != v) {
		a[u] += x; a[v] += x;
		u = par[u]; v = par[v];
	}
	a[u] += x;
	return ;
}

int get(int u, int v) {
	int res = 0;
	while (h[u] > h[v]) {
		res = __gcd(res, a[u]);
		u = par[u];
	}
	while (h[v] > h[u]) {
		res = __gcd(res, a[v]);
		v = par[v];
	}
	while (u != v) {
		res = __gcd(res, a[u]); res = __gcd(res, a[v]);
		u = par[u]; v = par[v];
	}
	res = __gcd(res, a[u]);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("GCDIX.inp", "r", stdin);
   	freopen("GCDIX.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, 0);
	while (m--) {
		int ope, u, v; cin >> ope >> u >> v;
		if (ope == 1) {
			int x; cin >> x;
			upd(u, v, x);
		}
		else cout << get(u, v) << '\n';
	}
}