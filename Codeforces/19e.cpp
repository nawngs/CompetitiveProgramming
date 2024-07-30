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

int n, m, h[NMAX + 3], f[NMAX + 3][2], bcke = 0, id = 0, par[NMAX + 3];

int vs[NMAX + 3];

vector < pii > adj[NMAX + 3];

bool check(int x) {
	queue < int > q;
	vs[x] = 1; q.push(x);
	bool th = 1;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto v : adj[u]) {
			if (vs[v.fi] == 0) {
				vs[v.fi] = (vs[u] == 1 ? 2 : 1);
				q.push(v.fi);
			}
			else if (vs[v.fi] == vs[u]) th = 0;
		}
	}
	return th;
}

void dfs(int u, int e) {
	for (auto x : adj[u]) if (x.fi != e) {
		int v = x.fi, idx = x.se;
		if (!h[v]) {
			h[v] = h[u] + 1;
			par[v] = idx;
			dfs(v, u);
			f[u][0] += f[v][0]; f[u][1] += f[v][1];
		}
		else if (h[u] > h[v]) {
			if (h[u] % 2 == h[v] % 2) {
				bcke ++; id = idx;
				f[u][0] ++, f[v][0] --;
			}
			else f[u][1] ++, f[v][1] --;
		}
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb({v, i}); adj[v].pb({u, i});
	}
	int cnt = 0, dem = 0, root;
	for (int i = 1; i <= n; i++) if (!vs[i]) {
		dem ++;
		if (check(i)) cnt ++;
		else root = i;
	}
	//if (th) cout << cnt << " " << dem << '\n';
	if (cnt == dem) {
		cout << m << '\n';
		for (int i = 1; i <= m; i++) cout << i << ' ';
		return 0;
	}
	if (dem - cnt > 1) {
		cout << 0 << '\n';
		return 0;
	}

	vector < int > res;
	h[1] = 1;
	dfs(root, 0);
	for (int i = 1; i <= n; i++) 
		if (par[i] && f[i][0] == bcke && f[i][1] == 0) res.pb(par[i]);
	if (bcke == 1) res.pb(id);
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (auto x : res) cout << x << " ";
}