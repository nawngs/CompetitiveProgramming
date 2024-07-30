#include <bits/stdc++.h>

#define name "gcd-graph"
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
const int N = 1e7;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k, q, par[NMAX + 3], id[N + 3];

int find(int u) {
	return (par[u] == u ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return ;
	par[v] = u;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) par[i] = i;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (id[x] != 0) {
			if (x > k) merge(id[x], i);
		}
		else id[x] = i;
	}
	for (int i = k + 1; i <= N; i++) {
		int val = -1;
		for (int j = i; j <= N; j+=i) if (id[j]) {
			if (val == -1) val = id[j];
			else merge(val, id[j]);
		}
	}
	while (q--) {
		int u, v; cin >> u >> v;
		if (find(u) == find(v)) cout << "Y";
		else cout << "N";
	}
}