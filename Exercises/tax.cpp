#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "tax";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E15;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, b[100003], num[100003], low[100003], timer = 0, scc, m, k, id_scc[100003], to_scc[100003];

ll dp[100003][203], ans;

pii edges[200003];

vector < int > val_scc[100003];

vector < int > adj[100003], adj_scc[100003];

bool deleted[100003], vs[100003];

stack < int > st;

void dfs(int u) {
	num[u] = low[u] = ++ timer;
	st.push(u);
	for (auto v : adj[u]) {
		if(deleted[v]) continue;
		if(!num[v]){
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}
	if (num[u] == low[u]) {
		scc ++;
		while (st.top() != u) {
			deleted[st.top()] = true;
			id_scc[st.top()] = scc;
			val_scc[scc].push_back(b[st.top()]);
			st.pop();
		}
		deleted[st.top()] = true;
		id_scc[st.top()] = scc;
		val_scc[scc].push_back(b[st.top()]);
		st.pop();
	}
}

void dfs_scc(int u) {
	vs[u] = 1;
	for (int i = 0; i <= k; i++) {
		if(i < (int)val_scc[u].size()) dp[u][i] = (1ll * val_scc[u][i] * 1ll * (val_scc[u].size() - i));
		else dp[u][i] = 0;
	}
	for (auto v : adj_scc[u]) {
		if (!vs[v]) dfs_scc(v);
		for (int i = k; i >= 0; i--) 
			for (int j = min(i, (int)val_scc[u].size() - 1); j >= 0; j--) {
				dp[u][i] = max(dp[u][i], dp[v][i - j] + (1ll * val_scc[u][j] * 1ll * ((int)val_scc[u].size() - j)));
			}	
	}
	for (int i = 0; i <= k; i++) ans = max(ans, dp[u][i]);
}

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= scc; i++) {
		val_scc[i].clear();
		adj_scc[i].clear();
		to_scc[i] = 0;
		vs[i] = 0;
	}
	scc = 0;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		deleted[i] = false;
		num[i] = low[i] = 0;
	}
	while (st.size()) st.pop();
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		edges[i] = {u, v};
	}
	timer = 0;
	for (int i = 1; i <= n; i++) if (!num[i]) dfs(i);
	for (int i = 1; i <= scc; i++) sort(val_scc[i].begin(), val_scc[i].end());
	for (int i = 1; i <= m; i++) {
		int u = edges[i].fi, v = edges[i].se;
		if (id_scc[u] != id_scc[v]) adj_scc[id_scc[u]].push_back(id_scc[v]);
	}
	ans = 0;
	for (int i = 1; i <= scc; i++) if (!vs[i]) dfs_scc(i);
	cout << ans << '\n';
}

int main() {
	fast;
	 fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
