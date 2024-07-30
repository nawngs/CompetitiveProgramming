#include <bits/stdc++.h>

#define name "gcdpath"
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
const int NMAX = 3e5;
const int N = 15e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[NMAX + 3], par[NMAX + 3], p[NMAX + 3];

bool used[NMAX + 3];

ll cnt[N + 3], sze[NMAX + 3];

vector < int > adj[NMAX + 3];

vector < pii > edges[N + 3];

int find(int u) {
	return (par[u] == u ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return ;
	sze[u] += sze[v]; par[v] = u;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	int O; cin >> O;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		par[i] = i; sze[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		edges[__gcd(a[u], a[v])].pb({u, v});
	}
	vector < int > temp;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j+=i) {
			for (auto x : edges[j]) {
				merge(x.fi, x.se);
				temp.pb(x.fi); temp.pb(x.se);
			}
		}
		for (auto x : temp) if (!used[x]) {
			used[x] = 1;
			if (x == par[x]) cnt[i] += sze[x] * (sze[x] - 1) / 2;
			par[x] = x; sze[x] = 1;
		}
		for (auto x : temp) used[x] = 0;
		temp.clear();
	}
	ll res = 0;
	for (int i = N; i >= 1; i--) {
		for (int j = 2 * i; j <= N; j+=i) cnt[i] -= cnt[j];
		res += 1ll * i * cnt[i];
	}
	cout << res;
}