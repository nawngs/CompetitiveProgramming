#include <bits/stdc++.h>

#define name ""
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

int n, m, q, par[100003][20], in[100003], out[100003], timer = 0, dp[100003], pre[100003];

pii edges[100003];

vector < int > adj[100003];

void dfs(int u) {
	dp[u] = 1;
	in[u] = ++ timer;
	for (int i = 1; i <= 19; i++) 
		par[u][i] = par[par[u][i - 1]][i - 1];
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		par[v][0] = u; dfs(v);
	}
	out[u] = timer;
}

int bit[100003];

void update(int pos, int val) { for (; pos <= n; pos += (pos & (-pos))) bit[pos] += val; }

int query(int pos) {
    int ans = 0;
    for (; pos; pos -= (pos & (-pos))) ans += bit[pos];
    return ans;
}

int find(int u) {
	int tmp = query(in[u]), res = u;
	for (int i = 19; i >= 0; i--) 
		if (par[res][i] && query(in[par[res][i]]) == tmp) 
			res = par[res][i];
	return res;
}

bool activate[100003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> q;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
		edges[i] = {u, v};
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		update(in[i], -1), update(out[i] + 1, 1);
	}
	while (m--) {
		int x; cin >> x;
		int u = edges[x].fi, v = edges[x].se;
		if (par[u][0] == v) swap(u, v);
		if (activate[x]) {
			dp[v] = pre[v] = dp[find(u)];
			update(in[v], -1); update(out[v] + 1, 1);
		}
		else {
			dp[find(u)] += dp[v] - pre[v];
			update(in[v], 1); update(out[v] + 1, -1);
		}
		activate[x] ^= 1;
	}
	while (q--) {
		int x; cin >> x; cout << dp[find(x)] << '\n';
	}
}