#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "dtree";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Dsu {
	int par[600009];
	void init(int m) {
		for (int i = 1; i <= 2 * m; i++) par[i] = i;
	}
	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = find_root(par[u]);
	}
	void join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_v == root_u) return ;
		par[root_v] = root_u;
	}
} dsu;

int n, h[300003], par[300003][20], log2_n, m, belong[300003][20];

bool invalid[600009];

vector < int > adj[300004];

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		par[v][0] = u;
		dfs(v);
	}
}

void init() {
	for (int j = 1; j <= log2_n; j++) 
		for (int i = 1; i <= n; i++) par[i][j] = par[par[i][j - 1]][j - 1];
}

int get_opp(int x) {
	if (x > m) return x -= m;
	else return x += m;
}

void update(int v, int j, int pos) {
	if (belong[v][j] == -1) belong[v][j] = pos;
	else {
		dsu.join(belong[v][j], pos);
		dsu.join(get_opp(belong[v][j]), get_opp(pos));
		belong[v][j] = dsu.find_root(pos);
	}
}

void LCA(int u, int v, int pos) {
	int opp = get_opp(pos);
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j--) 
			if (h[par[v][j]] >= h[u]) {
				update(v, j, pos);
				v = par[v][j];
			}
	}
	if (u == v) return ;
	for (int j = log2_n; j >= 0; j--) {
		if (par[u][j] != 0 && par[u][j] != par[v][j]) {
			update(v, j, pos);
			update(u, j, opp);
			u = par[u][j];
			v = par[v][j];
		}
	}
	update(v, 0, pos);
	update(u, 0, opp);
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

void sol() {
	cin >> n >> m;
	dsu.init(m);
	log2_n = log2(n) + 1;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	} 	
	dfs(1);
	init();
	memset(belong, 255, sizeof(belong));
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		LCA(u, v, i);
	}
	int dem1 = 0;
	for (int j = log2_n; j > 0; j--) {
		for (int i = 1; i <= n; i++) {
			if (belong[i][j] != -1) {
				update(i, j - 1, belong[i][j]);
				update(par[i][j - 1], j - 1, belong[i][j]);
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (dsu.find_root(i) == dsu.find_root(i + m)) {
			cout << 0 << '\n';
			return ;
		}
	}
	for (int i = 2; i <= n; i++) if (belong[i][0] == -1) dem1 ++;
	ll res = mu(2, dem1);
	dem1 = 0;
	for (int i = 1; i <= n; i++) {
		if (belong[i][0] != -1) {
			int temp = dsu.find_root(belong[i][0]);
			if (!invalid[temp]) dem1 ++;
			invalid[temp] = 1;
			invalid[get_opp(temp)] = 1;
		}
	}
	res = (res * mu(2, dem1)) % MOD;
	cout << res;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
