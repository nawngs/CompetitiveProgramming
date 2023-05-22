#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[300003], sze[300003];

bool used[300003];

vector < int > adj[300003];

int dfs_get_size(int u, int e) {
	sze[u] = 1;
	for (auto v : adj[u]) {
		if (used[v] || v == e) continue;
		sze[u] += dfs_get_size(v, u);
	}
	return sze[u];
}

int get_centroid(int u, int ms, int e) {
	for (auto v : adj[u]) {
		if (used[v] || v == e) continue;
		if (sze[v] * 2 > ms) return get_centroid(v, ms, u);
	}
	return u;
}

ll res = 0;

map < int, int > f;

void dfs2(int u, int e, int cur, int max_cur, int min_cur, bool UpdRes, bool first_time) {
	max_cur = max(max_cur, cur); min_cur = min(min_cur, cur);
	if (UpdRes && a[u] == -1 && cur == min_cur) res += 1ll * f[-cur];
	if (UpdRes && cur == 0 && first_time) {
		if (a[u] == 1 && max_cur == 0) res ++;
		if (a[u] == -1 && min_cur == 0) res ++;
	}
	if (!UpdRes && a[u] == 1 && cur == max_cur) f[cur] ++;
	//if (UpdRes) cout << u << " " << cur << " " << res << '\n';
	for (auto v : adj[u]) {
		if (v == e || used[v]) continue;
		dfs2(v, u, cur + a[v], max_cur, min_cur, UpdRes, first_time); 
	}
}

void centroid(int u) {
	int C = get_centroid(u, dfs_get_size(u, 0), 0);
	used[C] = 1;
	 // cout << "//##############################################################################" << '\n';
	 // cout << C << '\n';
	f.clear();
	for (auto v : adj[C]) {
		if (!used[v]) {
			dfs2(v, C, a[C] + a[v], max(0, a[C]), min(0, a[C]), 1, 1);
			dfs2(v, C, a[v], 0, 0, 0, 1);
		}
	}
	f.clear();
	reverse(adj[C].begin(), adj[C].end());
	for (auto v : adj[C]) {
		if (!used[v]) {
			dfs2(v, C, a[C] + a[v], max(0, a[C]), min(0, a[C]), 1, 0);
			dfs2(v, C, a[v], 0, 0, 0, 0);
		}
	}
	//cout << res << '\n';
	for (auto v : adj[C]) 
		if (!used[v]) 
			centroid(v);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		a[i] = (c == '(' ? 1 : -1);
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	centroid(1);
	cout << res;
}