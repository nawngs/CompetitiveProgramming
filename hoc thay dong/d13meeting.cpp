#include <bits/stdc++.h>

#define name ""
#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, par[100003][20], h[100003];

vector < int > adj[100003];

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	for (int i = 1; i <= 19; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		par[v][0] = u;
		dfs(v);
	}
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	for (int i = 19; i >= 0; i--) 
		if (h[par[v][i]] >= h[u]) v = par[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (par[v][i] != par[u][i]) 
			v = par[v][i], u = par[u][i];
	return par[u][0];
}

ll fx(int R, int L, int a, int b, int x) {
	return x * (x + 1) * a / 2 + (L - x) * (2 * R + L - x + 1) * b / 2;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1);
	while (q--) {
		int u, i, j, a, b;
		cin >> u >> i >> j >> a >> b;
		vector < int > temp;
		temp.pb(LCA(u, i)); temp.pb(LCA(u, j)); temp.pb(LCA(i, j));
		sort(temp.begin(), temp.end(), [&](int &x, int &y) {
			return h[x] > h[y];
		});
		int C = temp[0];
		int L = h[i] + h[C] - 2 * h[LCA(i, C)], R = h[j] + h[C] - 2 * h[LCA(j, C)];
		double x = 1.0 * (1.0 * b * L + 1.0 * b * R - 1.0 * (a - b) / 2.0) / (1.0 * (a + b));
		int upx = ceil(x), underx = floor(x); 
		upx = max(upx, 0ll); underx = max(underx, 0ll);
		ll temp1 = R * (R + 1) * a / 2 + min(fx(R, L, a, b, min(upx, L)), fx(R, L, a, b, min(underx, L)));
		ll temp2 = L * (L + 1) * a / 2 + min(fx(L, R, a, b, min(upx, R)), fx(L, R, a, b, min(underx, R)));
		cout << min(temp1, temp2) << '\n';
	}
}
