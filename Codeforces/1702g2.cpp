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

const string NAME = "";
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

void sol() {
	
}

int n, h[200003], par[200003][23], log2_n;

bool used[200003];

vector < int > adj[200003];

void dfs(int u) {
	h[u] = h[par[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v == par[u][0]) continue;
		par[v][0] = u;
		dfs(v);
	}
}

void init() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= log2_n; j++) par[i][j] = 0;

	for (int j = 1; j <= log2_n; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			//cout << i << " " << j << " " << par[i][j] << '\n';
		}
	}
	
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j--) {
			if (h[par[v][j]] >= h[u]) {
				v = par[v][j];
			}
		}
	}
	//cout << u << " " << v << '\n';
	if (u == v) return u;
	for (int j = log2_n; j >= 0; j--) {
		if (par[u][j] != 0 && par[v][j] != par[u][j]) {
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}

int main() {
	fast;
	//fre();
	cin >> n;
	log2_n = log2(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	init();
	int q;
	cin >> q;
	while (q--) {
		int k;
		vector < int > a(k);
		for (int i = 0; i < k; i++) used[i] = false;
		cin >> k;
		for (int i = 0; i < k; i++) cin >> a[i];
		sort(a.begin(), a.end(), [&](int &x, int &y) {
			return h[x] > h[y];
		});
		for (int i = 0; i < k; i++) if (LCA(a[i], a[0]) == a[i]) used[i] = 1;
		int cur = 0;
		while (cur < k && used[cur]) cur ++;
		if (cur == k) {
			cout << "YES\n";
			continue;
		}
		for (int i = cur; i < k; i++) if (LCA(a[i], a[1]) == a[i]) used[i] = 1;
		bool res = 1;
		for (int i = 0; i < k; i++) res &= used[i];
		res &= (h[LCA(a[0], a[cur])] >= h[a.back()]);
		cout << (res ? "YES" : "NO") << '\n';
	}
}
