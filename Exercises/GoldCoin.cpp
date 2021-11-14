#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "GoldCoin";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[200005], up[200005], down[200005], dp[200005];

vector < pll > adj[200005];

void dfs(int u, int e) {
	down[u] = a[u];
	vector < pll > maxdown;
	maxdown.clear();
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		up[v.fi] = max(a[v.fi], up[u] + v.se);
		dfs(v.fi, u);
		down[u] = max(down[u], down[v.fi] + v.se);
		maxdown.push_back({down[v.fi] + v.se, v.fi});
	}
	sort(maxdown.begin(), maxdown.end());
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		if (v.fi == maxdown[maxdown.size() - 1].se && maxdown.size() >= 2) up[v.fi] = max(up[v.fi], maxdown[maxdown.size() - 2].fi + v.se);
		if (v.fi != maxdown[maxdown.size() - 1].se) up[v.fi] = max(up[v.fi], maxdown[maxdown.size() - 1].fi + v.se);
	}
}

void dfs2(int u, int e) {
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		up[v.fi] = max(up[v.fi], up[u] + v.se);
		dfs2(v.fi, u);
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	up[1] = a[1];
	dfs(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++) cout << max(down[i], up[i]) << '\n';
}

int main() {
	fast;
		fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
