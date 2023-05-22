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

const string NAME = "moji";
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

struct Edge {
	ll u, v, l, id;
	Edge(ll _u, ll _v, ll _l, ll _id) : u(_u), v(_v), l(_l), id(_id) {};
};

ll cost, n, k, m, p, par[300003];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool join(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	par[v] = u;
	return true;
}

vector < Edge > edges;

int main() {
	fast;
	fre();	
	cin >> cost >> n;
	for (int i = 1; i <= n; i++)
		par[i] = i;
	cin >> k; 
	int shop;
	cin >> shop;
	for (int i = 1; i < k; i++) {
		int x; cin >> x;
		join(shop, x);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		ll u, v, l; cin >> u >> v >> l;
		edges.push_back({u, v, l, i});
	}
	sort(edges.begin(), edges.end(), [&](Edge &x, Edge &y) {
		return x.l > y.l || (x.l == y.l && x.id > y.id);
	});
	ll res = 0;
	vector < int > v1, v2;
	for (auto e : edges) {
		if (!join(e.u, e.v)) {
			res += cost * e.l;
			v1.push_back(e.id);
		}
	}
	edges.clear();
	cin >> p;
	for (int i = 1; i <= p; i++) {
		ll u, v, l; cin >> u >> v >> l;
		edges.push_back({u, v, l, i});
	}
	sort(edges.begin(), edges.end(), [&](Edge &x, Edge &y) {
		return x.l < y.l || (x.l == y.l && x.id < y.id);
	});
	for (auto e : edges) {
		if (join(e.u, e.v)) {
			res += cost * e.l;
			v2.push_back(e.id);
		}
	}
	cout << res << '\n';
	cout << v1.size() << '\n';
	sort(v1.begin(), v1.end());
	for (auto x : v1) cout << x << " ";
	cout << '\n';
	cout << v2.size() << '\n';
	sort(v2.begin(), v2.end());
	for (auto x : v2) cout << x << " ";
	cout << '\n';
}
