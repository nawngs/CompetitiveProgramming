// Judges with GCC >= 12 only needs Ofast
#pragma GCC optimize("O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize")
// MLE optimization
// #pragma GCC optimize("conserve-stack")
// Old judges
// #pragma GCC target("sse4.2,popcnt,lzcnt,abm,mmx,fma,bmi,bmi2")
// New judges. Test with assert(__builtin_cpu_supports("avx2"));
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// Atcoder
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
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
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LG = 18;

int n, a[N + 3], f[N + 3], par[N + 3][LG + 3], h[N + 3], in[N + 3], out[N + 3], timer = 0;

vector < int > id[N + 3];

vector < pll > G[N + 3];

vector < int > adj[N + 3];

void sieve() {
	for (int i = 1; i <= N; i++) f[i] = i;
	for (int i = 2; i * i <= N; i++) if (f[i] == i)
		for (int j = i * i; j <= N; j+=i) f[j] = i;
}

void dfs(int u, int e) {
	in[u] = ++ timer; h[u] = h[e] + 1;
	par[u][0] = e;
	for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
	for (auto v : adj[u]) if (v != e) 
		dfs(v, u);
	out[u] = timer;
}

int LCA(int u, int v) {
    if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = LG; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				v = par[v][j];
			}
		}
	}
	if (u == v) return u;
	for (int j = LG; j >= 0; j--) {
		if (par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

ll res = 0, cnt[N + 3], dem = 0;

ll mul(const ll &x, const ll &y) {
	return (x * y) % MOD;
}

ll add(const ll &x, const ll &y) {
	ll ans = x + y;
	if (ans >= MOD) ans -= MOD;
	return ans;
}

ll Minus(const ll &x, const ll &y) {
	return (x - y + MOD) % MOD;
}

void calc(int u, int x) {
	cnt[u] = (a[u] % x == 0);
	for (auto v : G[u]) {
		calc(v.fi, x);	
		cnt[u] += cnt[v.fi];
	}
	for (auto it : G[u]) {
		int v = it.fi, w = it.se;
		ll in2 = (cnt[v] * (cnt[v] - 1) / 2) % MOD;
		ll out = dem - cnt[v];
		ll out2 = (out * (out - 1) / 2) % MOD;
		res = add(res, mul(w, add(mul(in2, out), mul(cnt[v], out2))));
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	sieve();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		while (a[i] > 1) {
			int div = f[a[i]];
			id[div].pb(i);
			while (a[i] % div == 0) a[i] /= div;
		}
		a[i] = x;
	}
	dfs(1, 0);
	stack < int > st;
	ll ans = 0;
	for (int i = 2; i <= N; i++) if (f[i] == i && SZE(id[i])) {
		sort(id[i].begin(), id[i].end(), [&](int &x, int &y) {
			return in[x] < in[y];
		});
		int m = SZE(id[i]);
		for (int j = 1; j < m; j++) id[i].pb(LCA(id[i][j], id[i][j - 1]));
		sort(id[i].begin(), id[i].end(), [&](int &x, int &y) {
			return in[x] < in[y];
		});
		id[i].erase(unique(id[i].begin(), id[i].end()), id[i].end());
		while (!st.empty()) st.pop();
		dem = 0;
		for (auto u : id[i]) {
			dem += (a[u] % i == 0);
			G[u].clear();
			while (st.size() && out[st.top()] < in[u]) st.pop();
			if (st.size()) G[st.top()].push_back({u, h[u] - h[st.top()]});
			st.push(u);
		}
		res = 0;
		calc(id[i][0], i); 
		ans = add(ans, res);
	}
	cout << ans;
}