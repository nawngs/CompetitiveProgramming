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

const string NAME = "evoltree";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".ans";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k;
string s[1005];

struct Edges {
	int u, v, c;
	Edges(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {};
};

vector < Edges > edges;

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

	bool join(int u, int v) {
		int root_u = find_root(u);
		int root_v = find_root(v);
		if (root_u == root_v) return false;
		par[root_v] = root_u;
		return true;
	}

} dsu;

int main() {
	fast;
	fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
		for (int j = i - 1; j >= 1; j --) {
			int dem = 0;
			for (int p = 1; p <= k; p++) dem += (s[i][p] != s[j][p]);
			edges.push_back({i, j, dem});
		}
	}
	sort(edges.begin(), edges.end(), [](Edges &x, Edges &y) {
		return x.c < y.c;
	});
	dsu.init(n);
	ll ans = 0;
	for (auto e : edges) {
		if (!dsu.join(e.u, e.v)) continue;
		ans += e.c;
	}
	cout << ans;
}
