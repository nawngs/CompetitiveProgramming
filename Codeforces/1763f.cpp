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

int n, m, par[200003][20], s[200003], num[200003], low[200003], timeDFS = 0, h[200003], val[200003];

vector < int > adj[200003], g[200003];

bool incycle[200003];

stack < int > st;

void dfs(int u, int e) {
	num[u] = low[u] = ++ timeDFS;
	st.push(u);
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (!num[v]) {
			g[u].push_back(v);
			g[v].push_back(u);
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (num[u] == low[u]) {
		int cnt = 0;
		vector < int > temp;
		while (st.top() != u) {
			temp.push_back(st.top());
			incycle[st.top()] = 1;
			st.pop();
		}
	 	temp.push_back(st.top());incycle[st.top()] = 1; st.pop();
		for (auto x : temp) {
			for (auto v : adj[x]) 
				if (incycle[v]) cnt ++;
			incycle[x] = false;
		}
		s[u] = cnt;
		for (auto x : temp) val[x] = cnt;
	}
}

void dfs2(int u, int e) {
	cout << u << " " << s[u] << '\n';
	h[u] = h[e] + 1;
	for (auto v : g[u]) {
		if (v == e) continue;
		par[v][0] = u;
		s[v] += s[u];
		dfs2(v, u);
	}
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = 19; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				v = par[v][j];
			}
		}
	}
	//cout << u << " " << v << '\n';
	if (u == v) return u;
	for (int j = 19; j >= 0; j--) {
		if (par[u][j] != 0 && par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for (int j = 1; j <= 19; j++)
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}

	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		if (u == v) {
			cout << 0 << '\n';	
			continue;
		}
		int c = LCA(u, v);
		cout << s[u] + s[v] - 2 * s[c] + val[c] << '\n';
	}
}