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

const string NAME = "MST";
const string NAME2 = "TEST";
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

ll n, a[200005], up[200005], down[200005], cnt_up[200005], cnt_down[200005];

vector < pll > adj[200005];

void dfs(int u, int e) {
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		dfs(v.fi, u);
		down[u] += down[v.fi] + (cnt_down[v.fi] + 1) * v.se;
		cnt_down[u] += cnt_down[v.fi] + 1;
	}
}

void dfs2(int u, int e) {
	for (auto v : adj[u]) {
		if (v.fi == e) continue;
		cnt_up[v.fi] = cnt_up[u] + 1 + cnt_down[u] - cnt_down[v.fi] - 1;
		up[v.fi] += up[u] + (down[u] - down[v.fi] - (cnt_down[v.fi] + 1) * v.se) + v.se * cnt_up[v.fi];
		dfs2(v.fi, u);
	}
}

void sol() {
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i < n; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	dfs(1, 0);
	dfs2(1, 0);
	ll ans = INF;
	for (int i = 1; i <= n; i++) {
		//cout << i << " " << up[i] << " " << down[i] << " " << '\n';
		ans = min(ans, up[i] + down[i] + sum + a[i] * (n - 2));
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
