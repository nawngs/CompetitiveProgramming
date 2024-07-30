#include <bits/stdc++.h>

#define name "scc"
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
const int INF = 2e9 + 7;
const ll LINF = 1E18;
const int NMAX = 3000;
const int MMAX = 5000;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, in[NMAX + 3], low[NMAX + 3], timer = 0, scc = 0;

bool deleted[NMAX + 3];

pair < int, pii > ed[MMAX + 3];

vector < int > adj[NMAX + 3];

stack < int > st;

void dfs(int u) {
	in[u] = low[u] = ++ timer;
	st.push(u);
	for (auto v : adj[u]) {
		if (deleted[v]) continue;
		if (!in[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], in[v]);
	}
	if (in[u] == low[u]) {
		scc ++;
		while (st.top() != u) deleted[st.top()] = 1, st.pop();
		deleted[st.top()] = 1; st.pop();
	}
}

bool check(int l, int r) {
	for (int i = 1; i <= n; i++) adj[i].clear(), in[i] = low[i] = deleted[i] = 0;
	for (int i = l; i <= r; i++) adj[ed[i].se.fi].pb(ed[i].se.se);
	timer = scc = 0;
	dfs(1);
	for (int i = 1; i <= n; i++) if (!in[i]) return false;
	return (scc == 1);
	
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) 
		cin >> ed[i].se.fi >> ed[i].se.se >> ed[i].fi;
	sort(ed + 1, ed + m + 1);
	int res = INF;
	int r = 1;
	for (int i = 1; i <= m; i++) {
		r = max(i, r);
		while (r <= m && !check(i, r)) r++;
		// cout << i << " " << ans << '\n';
		if (r <= m) res = min(res, ed[r].fi - ed[i].fi);
	}
	cout << (res == INF ? -1 : res);
}