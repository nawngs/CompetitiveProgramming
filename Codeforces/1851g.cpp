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

int n, m, a[N + 3], par[N + 3];

bool ans[N + 3];

pii Q[N + 3];

pii h[N + 3];

vector < int > adj[N + 3], id[N + 3];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	par[v] = u;
	return true;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		adj[i].clear(); id[i].clear(); par[i] = i;
		cin >> h[i].fi; h[i].se = i;
		a[i] = h[i].fi;
	}
	sort(h + 1, h + n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		if (a[u] < a[v]) swap(u, v);
		adj[u].pb(v);
	}
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		ans[i] = 0;
		int u, v, w; cin >> u >> v >> w;
		int l = 1, r = n, mid, ans = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (h[mid].fi <= a[u] + w) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		id[ans].pb(i);
		Q[i] = {u, v};
	}
	for (int i = 1; i <= n; i++) {
		for (auto v : adj[h[i].se]) join(h[i].se, v);
		for (auto it : id[i]) ans[it] = (find(Q[it].fi) == find(Q[it].se));
	}
	for (int i = 1; i <= q; i++) cout << (ans[i] ? "YES" : "NO") << '\n';
	cout << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}