#include <bits/stdc++.h>

#define name "recover"
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
const int NMAX = 524300;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, nxt[NMAX + 3], id[NMAX + 3], pos[4 * NMAX + 3], MxNode = 0;

vector < int > adj[4 * NMAX + 3]; 
//canh tu node co max be hon den node co max lon

void build(int node, int l, int r) {
	if (l == r) {
		id[l] = node;
		pos[node] = l;
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid); build(node * 2 + 1, mid + 1, r);
	adj[node * 2].pb(node); adj[node * 2 + 1].pb(node);
}

void add_edge(int node, int l, int r, int u, int v, int finish) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		adj[node].pb(finish);
		return ;
	}
	int mid = (l + r) / 2;
	add_edge(node * 2, l, mid, u, v, finish); add_edge(node * 2 + 1, mid + 1, r, u, v, finish);
}

int vs[4 * NMAX + 3], res[NMAX + 3];

vector < int > topo;

bool dfs(int u) {
	vs[u] = 1;
	for (auto v : adj[u]) {
		if (vs[v] == 1) {
			return false;
		}
		if (!vs[v] && !dfs(v)) return false; 
	}
	vs[u] = 2;
	if (pos[u] != -1) topo.pb(u);
	return true;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nxt[i];
		id[i] = -1;
	}
	for (int i = 1; i <= n; i++) 
		if (nxt[i] != -1 && nxt[i] <= i) {
			cout << "No" << '\n';
			return ;
		}
	for (int i = 1; i <= 4 * n; i++) {
		pos[i] = -1;
		adj[i].clear();
		vs[i] = 0;
	}
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		if (nxt[i] == -1) continue;
		if (i + 1 <= nxt[i] - 1) add_edge(1, 1, n, i + 1, nxt[i] - 1, id[i]); 
		if (nxt[i] != n + 1) {
			adj[id[i]].pb(id[nxt[i]]);
			if (i + 1 <= nxt[i] - 1) add_edge(1, 1, n, i + 1, nxt[i] - 1, id[nxt[i]]);
		}
	}
	topo.clear();
	for (int i = 1; i <= 4 * n; i++) {
		if (!sz(adj[i])) {
			if (pos[i] != -1) topo.pb(i);
			continue;
		}
		if (!vs[i] && !dfs(i)) {
			cout << "No" << '\n';
			return ;
		} 
	}
	cout << "Yes" << '\n';
	reverse(topo.begin(), topo.end());
	int cnt = 0;
	for (auto x : topo) {
		if (pos[x] == -1) continue;
		res[pos[x]] = ++ cnt;
	}
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	cout << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int O; cin >> O;
	int t; cin >> t; while (t --) sol();
} //wtf tle 1 test???