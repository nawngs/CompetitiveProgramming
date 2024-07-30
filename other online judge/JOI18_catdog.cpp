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
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, par[NMAX + 3], sze[NMAX + 3], cid[NMAX + 3], chead[NMAX + 3], nc = 0, dp[NMAX + 3][2], color[NMAX + 3];

int in[NMAX + 3], timer = 0, val[NMAX + 3], out[NMAX + 3];

vector < int > adj[NMAX + 3];

int dfs(int u) {
	sze[u] = 1;
	for (auto v : adj[u]) if (v != par[u]) {
		par[v] = u;
		sze[u] += dfs(v);
	}
	return sze[u];
}

void hld(int u) {
	// cout << u << " " << nc << '\n';
	in[u] = ++ timer;
	val[in[u]] = u;
	cid[u] = nc;
	out[nc] = in[u];
	if (!chead[nc]) chead[nc] = u;
	int maxv = -1;
	for (auto v : adj[u]) if (v != par[u]) 
		if (maxv == -1 || sze[v] > sze[maxv]) maxv = v;
	if (maxv != -1) hld(maxv);
	for (auto v : adj[u]) if (v != par[u] && v != maxv) {
		nc ++;
		hld(v);
	}
}

struct Node {
	int f[2][2];
	Node() {
		for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			f[i][j] = INF;
	}
} it[4 * NMAX + 3];

bool minimize(int &x, const int &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

Node merge(const Node &x, const Node &y) {
	Node res;
	for (int x1 = 0; x1 < 2; x1++)
	for (int y1 = 0; y1 < 2; y1++)
	for (int x2 = 0; x2 < 2; x2++)
	for (int y2 = 0; y2 < 2; y2++)
		minimize(res.f[x1][y2], x.f[x1][y1] + y.f[x2][y2] + (y1 != x2));
	return res;
}

void build(int node, int l, int r) {
	if (l == r) {
		it[node].f[0][0] = it[node].f[1][1] = 0;
		it[node].f[0][1] = it[node].f[1][0] = INF;
		return ;
	}
	build(lnode); build(rnode);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node].f[0][0] = (color[val[pos]] != 1 ? dp[val[pos]][0] : INF);
		it[node].f[1][1] = (color[val[pos]] != 0 ? dp[val[pos]][1] : INF);
		return ;
	}
	update(lnode, pos); update(rnode, pos);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

Node query(int node, int l, int r, int u, int v) {
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	if (v <= mid) return query(node * 2, l, mid, u, v);
	else if (mid < u) return query(node * 2 + 1, mid + 1, r, u, v);
	return merge(query(lnode, u, v), query(rnode, u, v));
}

int update(int u) {
	int id = cid[u];
	while (u) {
		int head = chead[id], e = par[head];
		Node temp = query(1, 1, n, in[head], out[id]);
		dp[e][0] -= min({temp.f[0][0], temp.f[0][1], temp.f[1][0] + 1, temp.f[1][1] + 1});
		dp[e][1] -= min({temp.f[0][0] + 1, temp.f[0][1] + 1, temp.f[1][0], temp.f[1][1]});
		update(1, 1, n, in[u]);
		temp = query(1, 1, n, in[head], out[id]);
		dp[e][0] += min({temp.f[0][0], temp.f[0][1], temp.f[1][0] + 1, temp.f[1][1] + 1});
		dp[e][1] += min({temp.f[0][0] + 1, temp.f[0][1] + 1, temp.f[1][0], temp.f[1][1]});
		u = e; id = cid[u];
	}
	Node res = query(1, 1, n, 1, out[0]);
	int ans = INF;
	for (int i = 0; i < 2; i++)
	for (int j = 0; j < 2; j++) ans = min(ans, res.f[i][j]);
	return ans;
}

int cat(int u) {
	color[u] = 0; 
	return update(u);
}

int dog(int u) {
	color[u] = 1;
	return update(u);
}

int neighbor(int u) {
	color[u] = -1;
	return update(u);
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
	dfs(1); hld(1);
	build(1, 1, n);
	memset(color, 255, sizeof(color));
	int q; cin >> q;
	while (q--) {
		int type, u; cin >> type >> u;
		if (type == 1) cout << cat(u);
		if (type == 2) cout << dog(u);
		if (type == 3) cout << neighbor(u);
		cout << '\n';
	}
}