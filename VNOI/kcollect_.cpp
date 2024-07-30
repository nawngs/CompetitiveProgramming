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
const int N = 1e4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, a[N + 3], num[N + 3], low[N + 3], timer = 0, idx[N + 3], scc = 0, f[N + 3], g[N + 3];

string s[103];

vector < int > adj[N + 3], G[N + 3];

int getid(int i, int j){
	return (i - 1) * n + j;
}

bool valid(int i, int j) {
	return (i >= 1 && i <= m && j >= 1 && j <= n && s[i][j] != '#');
}

stack < int > st;

void dfs(int u) {
	// cout << u << '\n';
	num[u] = low[u] = ++ timer;
	st.push(u);
	for (auto v : adj[u]) if (idx[v] == 0) {
		if (!num[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (low[u] == num[u]) {
		scc ++;
		while (1) {
			idx[st.top()] = scc;
			f[scc] += a[st.top()];
			if (st.top() == u) {
				st.pop();
				break;
			}
			st.pop();
		}
	}
}

int dp(int u) {
	if (g[u] != -1) return g[u];
	g[u] = f[u];
	for (auto v : G[u]) g[u] = max(g[u], f[u] + dp(v));
 	return g[u];
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if(s[i][j] == '#') continue ;
			int id = getid(i, j);
			if ('0' <= s[i][j] && s[i][j] <= '9') a[id] = s[i][j] - '0';
			else a[id] = 0;
 			if (valid(i + 1, j)) adj[id].push_back(getid(i + 1, j));
			if (valid(i, j + 1)) adj[id].push_back(getid(i, j + 1));
			if (s[i][j] == 'W' && valid(i, j - 1)) adj[id].push_back(getid(i, j - 1));
			if (s[i][j] == 'N' && valid(i - 1, j)) adj[id].push_back(getid(i - 1, j));
		}
	}
	for (int i = 1; i <= n * m; i++) if (!num[i]) dfs(i);
	for (int u = 1; u <= n * m; u++) for (auto v : adj[u]) if (idx[u] != idx[v]) G[idx[u]].pb(idx[v]);
	memset(g, 255, sizeof(g));
	cout << dp(idx[1]);
}