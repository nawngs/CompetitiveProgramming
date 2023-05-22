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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, q, res[100003], low[100003], high[100003];

vector < int > adj[100003], players[100003], id[100003];

struct DSU {
	vector < int > par;
	void init(int n) {
		par.resize(n + 5, 0);
		for (int i = 1; i <= n; i++) par[i] = i;
	}
	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = find_root(par[u]);
	}
	bool join(int u, int v) {
		int root_u = find_root(par[u]);
		int root_v = find_root(par[v]);
		if (root_v == root_u) return false;
		par[root_v] = root_u;
		return true;
	}
};

pii edges[100003];

int main() {
	fast;
	//fre();
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		players[x].push_back(i);
	}
	for (int i = 1; i <= q; i++) {
		cin >> edges[i].fi >> edges[i].se;
		adj[edges[i].fi].push_back(edges[i].se);
		adj[edges[i].se].push_back(edges[i].fi);
	}
	for (int i = 1; i <= m; i++) {
		if (players[i].size() == 1) {
			res[i] = 0;
			low[i] = rand();
			high[i] = low[i] - 1;
		}
		else {
			res[i] = -1;
			low[i] = 1;
			high[i] = q;
		}
	}
	while (1) {
		bool th = false;
		for (int i = 1; i <= m; i++) {
			if (low[i] > high[i]) continue;
			id[(low[i] + high[i]) / 2].push_back(i);
		}
		DSU dsu;
		dsu.init(n);
		for (int i = 1; i <= q; i++) {
			dsu.join(edges[i].fi, edges[i].se);
			while (id[i].size()) {
				int game = id[i].back(); id[i].pop_back();
				th = 1;
				int par = dsu.find_root(players[game][0]);
				bool correct = 1;
				for (auto c : players[game]) {
					if (dsu.find_root(c) != par) {
						correct = false;
						break;
					}
				}
				if (correct) {
					res[game] = i;
					high[game] = i - 1;
				}
				else low[game] = i + 1;
			}
		}
		if (!th) break;
	}
	for (int i = 1; i <= m; i++) cout << res[i] << '\n'; 
}
