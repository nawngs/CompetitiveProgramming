#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, in[NMAX + 3], low[NMAX + 3], timer = 0, scc = 0, dp[NMAX + 3], num_scc[NMAX + 3];

bool vs[NMAX + 3];

vector < int > adj[NMAX + 3], G[NMAX + 3];

stack < int > st;

void dfs(int u) {
	in[u] = low[u] = ++ timer;
	st.push(u);
	for (auto v : adj[u]) {
		if (num_scc[v] != 0) continue;
		if (!in[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], in[v]);
	}
	if (low[u] == in[u]) {
		scc ++;
		int dem = 0;
		while (1) {
			num_scc[st.top()] = scc;
			dem ++;
			if (st.top() == u) {
				st.pop();
				break;
			}
			st.pop();
		}
		if (dem > 1) dp[scc] = INF;
		else dp[scc] = 0;
	}
}

void dfs_scc(int u) {
	if (vs[u]) return ;
	vs[u] = 1;
	for (auto v : G[u]) {
		dfs_scc(v);
		dp[u] = max(dp[u], dp[v] + 1);
	}
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		if (c == 1) v += n;
		else u += n;
		adj[u].pb(v);
	}
	for (int i = 1; i <= 2 * n; i++) if (!in[i]) dfs(i);
	for (int u = 1; u <= 2 * n; u++) {
		vs[num_scc[u]] = 0;
		for (auto v : adj[u]) if (num_scc[u] != num_scc[v]) G[num_scc[u]].pb(num_scc[v]);
	}
	for (int i = 1; i <= scc; i++) dfs_scc(i);
	for (int i = 1; i <= n; i++) {
		ll res = max(dp[num_scc[i]], dp[num_scc[i + n]]);
		cout << (res >= INF ? -1 : res) << '\n';
	}
}