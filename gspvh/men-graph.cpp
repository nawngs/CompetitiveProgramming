#include <bits/stdc++.h>

#define name "men-graph"
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
const int NMAX = 2e5;
const int N = 3e5;
const ll MOD = 998244353;
const ll BASE = 2309;

int n, m, par[NMAX + 3], in[NMAX + 3], cnt[N + 3], timer = 0, id[NMAX + 3], Chon[5][NMAX + 3];

ll fac[NMAX + 3], inv[NMAX + 3];

pii edges[N + 3];

vector < pii > adj[NMAX + 3];



ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll Ckn(int k, int n) {
	if (k > n) return 0;
	if (k == 0) return 1;
	return (fac[n] * ((inv[k] * inv[n - k]) % MOD)) % MOD;
}

ll C(int k, int n) {
	if (k > n) return 0;
	return Chon[k][n];
}

void add(int &x, const int y) {
	x += y;
	if (x < 0) x += MOD;
	if (x >= MOD) x -= MOD;
}

ll solve(int u, int v, int id) {
	int szeu = adj[u].size(), szev = adj[v].size();
	int ans = (C(2, szeu - 1) * C(3, szev - 1)) % MOD;
	int temp = (C(1, cnt[id]) * C(1, szeu - 2)) % MOD;
	temp = (temp * C(2, szev - 2)) % MOD;
	add(ans, -temp);
	temp = (C(2, cnt[id]) * C(0, szeu - 3)) % MOD;
	temp = (temp * C(1, szev - 3)) % MOD;
	add(ans, temp);
	return ans;
}

bool cmp(pii x, pii y) {
	if (adj[x.fi].size() == adj[y.fi].size()) return x.fi < y.fi;
	return adj[x.fi].size() < adj[y.fi].size();
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	fac[0] = 1; inv[0] = mu(fac[0], MOD - 2);
	for (int i = 1; i <= n; i++) {
		 fac[i] = (fac[i - 1] * i) % MOD;
		 inv[i] = mu(fac[i], MOD - 2);
	}
	for (int i = 0; i <= 4; i++) {
		for (int j = 0; j <= n; j++) Chon[i][j] = Ckn(i, j);
	}
	for (int i = 1; i <= m; i++) {
		cin >> edges[i].fi >> edges[i].se;
		adj[edges[i].fi].pb({edges[i].se, i}); adj[edges[i].se].pb({edges[i].fi, i});
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end(), cmp);
		for (auto x : adj[i]) id[x.fi] = x.se;
		for (auto x : adj[i]) {
			if (!cmp(x, mp(i, 0))) break;
			for (auto v : adj[x.fi]) if (id[v.fi]) {
				cnt[id[v.fi]] ++;
				cnt[x.se] ++;
				cnt[v.se] ++;
			}
		}
		for (auto x : adj[i]) id[x.fi] = 0;
	}
	for (int i = 1; i <= m; i++) cnt[i] /= 3;
	int res = 0;
	for (int i = 1; i <= m; i++) {
		add(res, solve(edges[i].fi, edges[i].se, i));
		add(res, solve(edges[i].se, edges[i].fi, i));
	}
	cout << res;
}