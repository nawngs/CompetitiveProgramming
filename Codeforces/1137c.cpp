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
const int NMAX = 5e6;
const int N = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, d, in[NMAX + 3], low[NMAX + 3], timer = 0, scc = 0, cur[N + 3], dp[NMAX + 3];

int sccid[NMAX + 3];

int s[N + 3][53];

vector < int > adj[NMAX + 3];

vector < int > G[NMAX + 3];

int id(int x, int y) {
	return (x - 1) * d + y;
}

stack < int > st;

void dfs(int u) {
	in[u] = low[u] = ++ timer;
	st.push(u);
	for (auto v : adj[u]) {
		if (!in[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], in[v]);
	}
	if (low[u] == in[u]) {
		scc ++;
		while (st.top() != u) {
			int v = st.top(); st.pop();
			sccid[v] = scc;
			int x = v / d + 1, y = v - (x - 1) * d;
			if (cur[x] != u && s[x][y] == 1) cur[x] = u, dp[scc] ++;
		}
		int v = st.top(); st.pop();
		sccid[v] = scc;
		int x = v / d + 1, y = v % d;
		if (cur[x] != u && s[x][y] == 1) cur[x] = u, dp[scc] ++;
	}
}

int calc(int u) {
	int res = 0;
	for (auto v : G[u]) 
		res = max(res, calc(v));
	return dp[u] + res;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> d;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		for (int j = 0; j < d; j++) adj[id(u, j)].pb(id(v, (j + 1) % d)); 
	}
	memset(cur, 255, sizeof(cur));
	for (int i = 1; i <= n; i++)
	for (int j = 0; j < d; j++) {
		char c; cin >> c;
		s[i][j] = c - '0';
	}
	for (int i = 0; i < n * d; i++) if (!in[i]) dfs(i);
	//for (int i = 0; i < n * d; i++) cout << i / d + 1 << " " << i % d << " " << sccid[i] << '\n';
	for (int i = 0; i < n * d; i++) 
		for (auto x : adj[i]) if (sccid[i] != sccid[x]) 
			G[sccid[i]].pb(sccid[x]);
	calc(sccid[0]);
	cout << calc(sccid[0]);
}