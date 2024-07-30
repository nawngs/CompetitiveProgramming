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

const string NAME = "twopaths";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, f[nmax + 3], g[nmax + 3], w[nmax + 3], par[nmax + 3], longest[nmax + 3], up[nmax + 3];

vector < int > adj[nmax + 3];

pii edges[nmax + 3];

void Dfs_First(int u) {
	vector < ll > temp;
	for (auto v : adj[u]) {
		if (v == par[u]) continue;
		par[v] = u;
		Dfs_First(v); 
		f[u] = max(f[u], f[v]);
		temp.push_back(longest[v] + w[u]);
	}
	while (temp.size() < 3) temp.push_back(w[u]);
	sort(temp.begin(), temp.end());
	longest[u] = temp.back();
	f[u] = max(f[u], temp.back() + temp[temp.size() - 2] - w[u]);	
}

void Dfs_Second(int u) {
	vector < ll > temp1, temp2;
	temp2.push_back(up[u]);
	for (auto v : adj[u]) {
		if (v == par[u]) continue;
		g[v] = g[u];
		temp1.push_back(f[v]);
		temp2.push_back(longest[v] + w[u]);
	}
	while (temp1.size() < 3) temp1.push_back(0);
	sort(temp1.begin(), temp1.end());
	while (temp2.size() < 3) temp2.push_back(w[u]);
	sort(temp2.begin(), temp2.end());
	for (auto v : adj[u]) {
		if (v == par[u]) continue;
		if (f[v] != temp1.back()) g[v] = max(g[v], temp1.back());
		else g[v] = max(g[v], temp1[temp1.size() - 2]);
		ll sum = temp2.back() + temp2[temp2.size() - 2] + temp2[temp2.size() - 3];
		if (longest[v] + w[u] > temp2[temp2.size() - 3]) 
			g[v] = max(g[v], sum - longest[v] - w[u] - w[u]);
		else g[v] = max(g[v], sum - temp2[temp2.size() - 3] - w[u]);
		if (longest[v] + w[u] == temp2.back()) up[v] = temp2[temp2.size() - 2] + w[v];
		else up[v] = temp2.back() + w[v];
		Dfs_Second(v);
	}
}

int main() {
	fast;
	// fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges[i] = {u, v};
	}
	Dfs_First(1);
	Dfs_Second(1);
	ll res = -LINF;
	for (int i = 1; i < n; i++) {
		int u = edges[i].fi, v = edges[i].se;
		if (par[u] == v) swap(u, v);
		res = max(res, g[v] + f[v]); 
	}
	cout << res;
}
