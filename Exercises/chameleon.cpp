#include <bits/stdc++.h>

#define name "CHAMELEON"
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
const int N = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, A, B, C, timer, num[N + 3], low[N + 3], res = 0, sz[N + 3];

bool joint[N + 3], bridge[N + 3];

vector < int > adj[N + 3], G[N + 3];

int dfs(int u, int e) {
	sz[u] = 1;
	num[u] = low[u] = ++ timer;
	int cnt = 0;
	for (auto v : adj[u]) if (v != e) {
		if (!num[v]) {
			cnt ++;
			G[u].pb(v);
			sz[u] += dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > num[u]) bridge[v] = 1;
			if (e == 0 && cnt > 1) joint[u] = 1;
			if (e != 0 && low[v] >= num[u]) joint[u] = 1;
		}
		else low[u] = min(low[u], num[v]);
	}
	return sz[u];
}

ll mul(ll a, ll b) {
	return a * b % MOD;
}

void add(ll &x, ll y) {
	if ((x += y) >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

namespace sub1 {
	void dfs(int u) {
		add(res, mul(B, n - 1));
		if (joint[u]) add(res, mul(B, mul(sz[u] - 1, n - sz[u])));
		ll temp = 0;
		for (auto v : G[u]) {
			if (bridge[v]) add(res, mul(A, mul(sz[v], n - sz[v])));
			if (joint[u]) add(res, mul(B, mul(temp, sz[v])));
			add(temp, sz[v]);
			dfs(v);
		}
	
	}
}

namespace sub2 {
	ll f[N + 3], g[N + 3], h[N + 3], demf, demg = 0; // f joint * joint, g joint * bridge, h bridge * bridge
	void dfs(int u) {
		add(res, mul(B, mul(B, n - 1)));
		if (joint[u]) {
			add(demf, mul(4, mul(sz[u] - 1, n - sz[u]))), add(f[u], sz[u] - 1), add(res, mul(B, mul(B, mul(sz[u] - 1, n - sz[u]))));
		}
		ll temp = 0;
		for (auto v : G[u]) {
			dfs(v);
			if (joint[u]) {
				add(demf, mul(4, mul(temp, sz[v])));
				add(res, mul(B, mul(B, mul(temp, sz[v]))));
				add(temp, sz[v]);
			}
			add(f[u], f[v]);
			add(h[u], h[v]);
			add(h[u], mul(g[v], g[u]));
			if (bridge[v]) {
				add(res, mul(A, mul(A, mul(sz[v], n - sz[v])))); 
				add(demg, mul(2, mul(sz[v], n - sz[v])));
				add(h[u], mul(g[v], n - sz[v]));
				add(h[u], mul(sz[v], g[u]));
				add(g[u], sz[v]);
			}
			add(g[u], g[v]);
		}
		// cout << u <<  " " << h[u] << " " << g[u] << '\n';
	}
	void reroot(int u, int e) {
		if (joint[u]) {
			for (auto v : G[u]) {
				add(demf, mul(f[v], n - sz[v] - 1));
				add(demg, mul(g[v], n - sz[v] - 1));
				if (bridge[v]) add(demg, mul(sz[v], n - sz[v] - 1));
			}
			if (e != 0) {
				add(demf, mul(f[e], n - sz[e] - 1));
				add(demg, mul(g[e], n - sz[e] - 1));
				if (bridge[u]) add(demg, mul(sz[e], n - sz[e] - 1));
			}
		}
		for (auto v : G[u]) {
			int szu = sz[u], szv = sz[v]; 
			add(sz[u], -sz[v]); add(f[u], -f[v]); add(g[u], -g[v]);
			if (bridge[v]) add(g[u], -sz[v]);
			if (joint[u]) add(f[u], -szu + 1), add(f[u], sz[u] - 1);
			add(sz[v], sz[u]); add(f[v], f[u]); add(g[v], g[u]);
			if (bridge[v]) add(g[v], sz[u]);
			if (joint[v]) add(f[v], -szv + 1), add(f[v], sz[v] - 1);
			reroot(v, u);
			szu = sz[u], szv = sz[v]; 
			add(sz[v], -sz[u]); add(f[v], -f[u]); add(g[v], -g[u]);
			if (bridge[v]) add(g[v], -sz[u]);
			if (joint[v]) add(f[v], -szv + 1), add(f[v], sz[v] - 1);
			add(sz[u], sz[v]);add(f[u], f[v]);add(g[u], g[v]);
			if (bridge[v]) add(g[u], sz[v]);
			if (joint[u]) add(f[u], -szu + 1), add(f[u], sz[u] - 1);
		}
	}
	void solve() {
		demf = (n * (n - 1)) % MOD;
		dfs(1);
		add(res, mul(h[1], mul(mul(2, A), A)));
		reroot(1, 0);
		// cout << h[1] << " " << demf / 2 << " " << demg << '\n';
		add(res, mul(demf, mul(B, B)));
		// cout << res << '\n';
		add(res, mul(demg, mul(mul(2, A), B)));
		// cout << res << '\n';
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> A >> B >> C;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, 0);
	if (C == 1) {
		// assert(0);
		sub1::dfs(1);
		cout << res << '\n';
	}
	else {
		sub2::solve();
		cout << res << '\n';
	}
}