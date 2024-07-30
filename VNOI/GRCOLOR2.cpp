#include <bits/stdc++.h>

#define name "GRCOLOR2"
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
const int LG = 17;

int n, h[NMAX + 3], par[NMAX + 3][LG + 3], in[NMAX + 3], timer = 0, out[NMAX + 3];

bool rem[NMAX + 3];

vector < int > adj[NMAX + 3], a;

bool used[NMAX + 3];

void dfs(int u) {
	in[u] = ++ timer;
	h[u] = h[par[u][0]] + 1;
	for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
	for (auto v : adj[u]) if (v != par[u][0]) {
		par[v][0] = u;
		dfs(v);
	}
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
	//cout << u << " " << v << '\n';
	if (u == v) return u;
	for (int j = LG; j >= 0; j--) {
		if (par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int calc(int u) {
	int cnt = 0, total = 0; rem[u] = used[u];
	for (auto v : adj[u]) {
		total += calc(v);
		cnt += rem[v];
	}
	if (cnt == 0) return total;
	if (!rem[u] && cnt == 1) {
		rem[u] = 1;
		return total;
	}
	if (used[u]) total += cnt;
	else total ++;
	return total;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1);
	int q; cin >> q;
	while (q--) {
		int k; cin >> k;
		a.resize(k);
		for (auto &x : a) {
			cin >> x;
			used[x] = 1;
		}
		sort(a.begin(), a.end(), [&](int &x, int &y) {
			return in[x] < in[y];
		});
		bool ok = 1;
		for (auto x : a) if (used[par[x][0]]) ok = 0;
		if (!ok) cout << -1 << '\n';
		else {
			for (int i = 1; i < k; i++) a.pb(LCA(a[i], a[i - 1]));
			sort(a.begin(), a.end(), [&](int &x, int &y) {
				return in[x] < in[y];
			});
			a.erase(unique(a.begin(), a.end()), a.end());
			stack < int > st;
			for (auto u : a) {
				adj[u].clear();
				while (st.size() && out[st.top()] < in[u]) 
					st.pop();
				if (st.size()) adj[st.top()].push_back(u);
				st.push(u);
			}
			cout << calc(a[0]) << '\n';
		}
		for (auto x : a) used[x] = 0;
	}
}