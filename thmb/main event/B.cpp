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

struct Data {
	int u, v, c;
	char l;
} a[200003];

int n, m, dem, res[200003], log2_n, h[200003], p[200003][19], len[200003][19];

vector < pii > adj[200003], query;

void dfs(int u) {
	h[u] = h[p[u][0]] + 1;
	for (auto v : adj[u]) {
		if (v.fi == p[u][0]) continue;
		len[v.fi][0] = v.se;
		p[v.fi][0] = u;
		dfs(v.fi);
	}
}

void init() {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= log2_n; j++) p[i][j] = -1;

	for (int j = 1; j <= log2_n; j++)
		for (int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			len[i][j] = max(len[i][j - 1], len[p[i][j - 1]][j - 1]);
		}

}

int LCA(int u, int v) {
	int res = 0;
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = log2_n; j >= 0; j --) {
			 if (h[p[v][j]] >= h[u]) {
			 	res = max(res, len[v][j]);
			 	v = p[v][j];
			 }
		} 
	}
	if (u == v) return res;
	for (int j = log2_n; j >= 0; j --) {
		if (p[u][j] != 0  && p[u][j] != p[v][j]) {
			res = max(res, len[u][j]);
			res = max(res, len[v][j]);
			u = p[u][j];
			v = p[v][j];
		}
	}
	res = max(res, max(len[u][0], len[v][0]));
	return res;
}

int main() {
	fast;
	fre();
	cin >> n >> m;
	log2_n = log2(n) + 1;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].l >> a[i].c;
		if (a[i].l != '?') {
			if (a[i].c == 1) {
				adj[a[i].u].push_back({a[i].v, a[i].l - '0'});
				adj[a[i].v].push_back({a[i].u, a[i].l - '0'});
			}
		}
		else {
			dem ++;
			if (a[i].c == 1) {
				adj[a[i].u].push_back({a[i].v, 1});
				adj[a[i].v].push_back({a[i].u, 1});
				res[dem] = 1;
			}
			else query.push_back({i, dem});
		}
	}
	dfs(1);
	init();
	for (auto x : query) res[x.se] = LCA(a[x.fi].u, a[x.fi].v);
	for (int i = 1; i <= dem; i++) cout << res[i] << ' ';
}
