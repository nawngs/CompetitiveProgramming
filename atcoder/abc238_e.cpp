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

struct Dsu {
	vector < int > par;
	void init(int n) {
		par.resize(n + 5, 0);
		for (int i = 1; i <= n; i++) par[i] = i;
	}
	int find_root(int u) {
		if (par[u] == u) return u;
		return par[u] = find_root(par[u]);
	}
	void join(int u, int v) {
		int root_u = find_root(par[u]);
		int root_v = find_root(par[v]);
		if (root_v == root_u) return ;
		par[root_v] = root_u;
	}
} dsu;

int n, q;

void sol() {
	cin >> n >> q;
	dsu.init(n);
	while (q --) {
		int l, r;
		cin >> l >> r;
		dsu.join(l - 1, r);
	}
	if (dsu.find_root(n) == dsu.find_root(0)) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
