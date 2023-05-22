#include <bits/stdc++.h>

#define name ""
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

ll n, dp[100003][3], a[100003], b[100003];

vector < int > adj[100003];

bool used[100003];

void dfs(int u, int e) {
	dp[u][0] = dp[u][1] = LINF; dp[u][2] = a[u];
	vector < ll > temp;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		dp[u][2] += min(dp[v][0], min(dp[v][1], dp[v][2]));
		temp.pb(min(dp[v][1], dp[v][2]) - min(dp[v][0], min(dp[v][1], dp[v][2])));
	}
	sort(temp.begin(), temp.end());
	if (sz(temp) >= b[u] - 1) {
		dp[u][0] = dp[u][2] - a[u];
		for (int i = 0; i < b[u] - 1; i++) dp[u][0] += temp[i];
	}
	if (sz(temp) >= b[u]) 
		dp[u][1] = dp[u][0] + temp[b[u] - 1];

}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	dfs(1, 0);
	cout << min(dp[1][1], dp[1][2]);
}
