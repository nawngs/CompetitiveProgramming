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
const int NMAX = 5e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LG = 20;

int n, q, sz;

ll s[NMAX + 3], h[NMAX + 3], p[NMAX + 3][LG + 3], in[NMAX + 3], out[NMAX + 3], timer = 0, dp[NMAX + 3], cnt[NMAX + 3], res;

vector < pll > adj[NMAX + 3];

vector < int > node;

void dfs(int u, int e) {
	in[u] = ++ timer;
	h[u] = h[e] + 1;
	for (int j = 1; j <= LG; j++) p[u][j] = p[p[u][j - 1]][j - 1];
	for (auto v : adj[u]) if (v.fi != e) {
		p[v.fi][0] = u;
		s[v.fi] = s[u] + v.se;
		dfs(v.fi, u);
	}
	out[u] = timer;
}

int LCA(int u, int v) {
    if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = LG; j >= 0; j--) {
			if (h[p[v][j]] >= h[u]) {
				v = p[v][j];
			}
		}
	}
	if (u == v) return u;
	for (int j = LG; j >= 0; j--) {
		if (p[v][j] != p[u][j]) {
			u = p[u][j];
			v = p[v][j];
		}
	}
	return p[u][0];
}

stack < int > st;

namespace sub1 {
	void solve() {
		while (q--) {
			node.clear();
			cin >> sz; node.resize(sz);
			for (auto &x : node) cin >> x;
			ll ans = LINF;
			for (int i = 1; i <= n; i++) {
				ll res = 0;
				for (auto x : node) res += s[i] + s[x] - 2 * s[LCA(i, x)];
				ans = min(ans, res);
			}
			cout << ans << '\n';
		}
	}
}

void calc(int u) {
	for (auto v : adj[u]) {
		calc(v.fi);
		cnt[u] += cnt[v.fi];
		dp[u] += dp[v.fi] + cnt[v.fi] * v.se;
	}
}

void solve(int u) {
	res = min(res, dp[u]);
	for (auto v : adj[u]) {
		dp[u] = dp[u] - dp[v.fi] - cnt[v.fi] * v.se;
		cnt[u] -= cnt[v.fi];
		cnt[v.fi] += cnt[u];
		dp[v.fi] += dp[u] + cnt[u] * v.se;
		solve(v.fi);
		cnt[v.fi] -= cnt[u];
		dp[v.fi] = dp[v.fi] - dp[u] - cnt[u] * v.se;
		cnt[u] += cnt[v.fi];
		dp[u] += dp[v.fi] + cnt[v.fi] * v.se;
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({v, c}); adj[v].pb({u, c});
	}
	dfs(1, 0);
	if (n <= 500 && q <= 500) {
		sub1::solve();
		return 0;
	}
	while (q--) {
		cin >> sz; node.clear(); node.resize(sz);
		for (auto &x : node) {
			cin >> x;
			cnt[x] = 1;
		}
		 sort(node.begin(), node.end(), [&](int &x, int &y) {
             return in[x] < in[y];
        });
        for (int i = 0; i < sz - 1; i++) node.pb(LCA(node[i], node[i + 1]));
        sort(node.begin(), node.end(), [&](int &x, int &y) {
             return in[x] < in[y];
        });
        node.erase(unique(node.begin(), node.end()), node.end());
         while (!st.empty()) st.pop();
       	 for (auto u : node) {
       	 	dp[u] = 0;
            adj[u].clear();
            while (st.size() && out[st.top()] < in[u]) st.pop();
            if (st.size()) {
                ll dis = s[u] - s[st.top()];
                adj[st.top()].pb({u, dis});
            }
            st.push(u);
        }
        res = LINF;
        calc(node[0]); solve(node[0]);
        for (auto u : node) cnt[u] = 0;
        cout << res << '\n';
	}
}