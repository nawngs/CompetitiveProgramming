#include <bits/stdc++.h>

#define name ""
#define int ll
#define test "test"
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

int n, a[100003];

ll dp[100003][4], f[100003], res = 0; 
//  0 la 1 thg di va co the di tiep, 1 la 1 thang di xong, 2 la 1 thg di xong con 1 thg co the di tiep, 3 la 2 thg deu di xong

vector < int > adj[100003];

void dfs(int u, int e) {
	vector < ll > temp;
	dp[u][0] = dp[u][1] = dp[u][2] = dp[u][3] = a[u];
	f[u] = a[u];
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		f[u] = max(f[u], f[v] + 1ll * a[u]);
		temp.push_back(f[v] + a[u]);
	}
	while (sz(temp) < 5) temp.push_back(a[u]);
	sort(temp.begin(), temp.end(), greater < ll > ());
	ll mx = 0;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dp[u][3] = max(dp[u][3], dp[v][3]);
		dp[u][3] = max(dp[u][3], dp[u][1] + dp[v][1]);
		dp[u][3] = max(dp[u][3], dp[v][2] + dp[u][0]);
		dp[u][3] = max(dp[u][3], dp[v][0] + dp[u][2]);
		dp[u][2] = max(dp[u][2], dp[v][1] + dp[u][0]);
		dp[u][2] = max(dp[u][2], dp[v][2] + a[u]);
		dp[u][2] = max(dp[u][2], dp[v][0] + a[u] + mx);
		dp[u][1] = max(dp[u][1], dp[v][1]);
		dp[u][1] = max(dp[u][1], dp[v][0] + dp[u][0]);
		dp[u][0] = max(dp[u][0], dp[v][0] + a[u]);
		mx = max(mx, dp[v][1]);
	}
	for (int i = 0; i < 4; i++) {
		//cout << u << " " << i << " " << dp[u][i] << '\n';
		res = max(res, dp[u][i]);
	}
}

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << res;
}