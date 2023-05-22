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

const string NAME = "merteam";
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

int n, q, a[100003];

struct Dsu {
	vector < int > par, max_val, min_val;
	void init(int n) {
		par.resize(n + 5);
		max_val.resize(n + 5);
		min_val.resize(n + 5);
		for (int i = 1; i <= n; i++) {
			par[i] = i;
			max_val[i] = min_val[i] = a[i];
		}
	}
	int find_root(int u) {
		return (par[u] == u ? u : par[u] = find_root(par[u]));
	}
	void join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return ;
		par[root_v] = root_u;
		max_val[root_u] = max(max_val[root_u], max_val[root_v]);
		min_val[root_u] = min(min_val[root_u], min_val[root_v]);
	}
} dsu;

int main() {
	fast;
	fre();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dsu.init(n);
	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			int u, v;
			cin >> u >> v;
			dsu.join(u, v);
		}
		else {
			int u;
			cin >> u;
			u = dsu.find_root(u);
			cout << dsu.max_val[u] << " " << dsu.min_val[u] << '\n';
		}
	}
}
