#include <bits/stdc++.h>

#define name "topo"
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
const int N = 4000;
const ll MOD = 998244353;
const ll BASE = 2309;

int n, fac[N + 3], inv[N + 3], dp[N + 3][N + 3], sze[N + 3], s[N + 3], f[N + 3];

vector < pii > adj[N + 3];

int sum(const int &x, const int &y) {
	return (x + y) % MOD;
}

void add(int &x, const int &y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int mul(const int &x, const int &y) {
	return 1ll * x * 1ll * y % MOD;
}

ll mu(int a, int b) {
	if (b == 0) return 1;
	int x = mu(a, b / 2);
	x = mul(x, x);
	if (b % 2 == 1) x = mul(x, a);
	return x;
}

ll Ckn(int k, int n) {
	if (k > n) return 0;
	return mul(fac[n], mul(inv[k], inv[n - k]));
}

void dfs(int u, int e) {
	dp[u][1] = 1; sze[u] = 1;
	for (auto it : adj[u]) if (it.fi != e) {
		int v, type; tie(v, type) = it;
		dfs(v, u);
		for (int i = 1; i <= sze[u] + sze[v]; i++) f[i] = 0;
		if (type) {
			s[sze[v] + 1] = 0;
			for (int i = sze[v]; i >= 1; i--) s[i] = sum(s[i + 1], dp[v][i]);
			
			for (int i = sze[u]; i >= 1; i--)
			for (int j = 0; j <= sze[v]; j++) 
				add(f[i + j], mul(Ckn(j, i + j - 1), mul(Ckn(sze[v] - j, sze[u] + sze[v] - i - j), mul(dp[u][i], s[j + 1]))));
		}
		else {
			s[0] = 0;
			for (int i = 1; i <= sze[v]; i++) s[i] = sum(s[i - 1], dp[v][i]);
			for (int i = sze[u]; i >= 1; i--)
			for (int j = 1; j <= sze[v]; j++) 
				add(f[i + j], mul(Ckn(j, i + j - 1), mul(Ckn(sze[v] - j, sze[u] + sze[v] - i - j), mul(dp[u][i], s[j]))));
		}
		sze[u] += sze[v];
		// cout << "edge: " << u << " " << v << '\n';
		// for (int i = 1; i <= sze[u]; i++) cout << i << " " << f[i] << '\n';
		for (int i = 1; i <= sze[u]; i++) dp[u][i] = f[i];
	}
	// cout << u << '\n';
	// for (int i = 1; i <= sze[u]; i++) cout << i << " " << dp[u][i] << '\n'; 
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb({v, 1}); adj[v].pb({u, 0});
	}
	fac[0] = 1; inv[0] = mu(fac[0], MOD - 2);
	for (int i = 1; i <= n; i++) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mu(fac[i], MOD - 2);
	}
	dfs(1, 0);
	int res = 0;
	for (int i = 1; i <= n; i++) add(res, dp[1][i]);
	cout << res;
}