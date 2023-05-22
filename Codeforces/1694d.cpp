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

int n, ans = 0, dp[200003];

pii a[200003];

vector < int > adj[200003];

void dfs(int u, int e) {
	int s = 0;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		s += dp[v];
	}
	if (s < a[u].fi) {
		ans ++;
		dp[u] = a[u].se;
	}
	else dp[u] = min(s, a[u].se);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	ans = 0;
	dfs(1, 0);
	cout << ans << '\n';
}

main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
