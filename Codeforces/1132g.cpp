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
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[NMAX + 3], k, nxt[NMAX + 3], in[NMAX + 3], out[NMAX + 3], timer = 0, it[6 * NMAX + 3], lazy[6 * NMAX + 3];

vector < int > adj[NMAX + 3];

void dfs(int u) {
	in[u] = ++ timer;
	for (auto v : adj[u]) 
		dfs(v);
	out[u] = timer;
}

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, int val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	n ++;
	nxt[n] = n; a[n] = INF;
	for (int i = n - 1; i >= 1; i--) {
		int &x = nxt[i]; x = i + 1;
		while (a[x] <= a[i]) x = nxt[x];
		adj[x].pb(i); 
	}
	dfs(n);
	for (int i = 1; i < k; i++) update(1, 1, n + 1, in[i], out[i], 1);
	for (int i = 1; i + k - 1 < n; i++) {
		update(1, 1, n + 1, in[i + k - 1], out[i + k - 1], 1);
		cout << it[1] << " ";
		update(1, 1, n + 1, in[i], out[i], -1);
	}
}