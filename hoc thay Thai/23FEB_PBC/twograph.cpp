#include <bits/stdc++.h>

#define name ""
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

struct Edge {
	int u, v, c, id;
	Edge(int _u, int _v, int _c, int _id) {
		u = _u, v = _v, c = _c; id = _id;
	}
};

int n1, m1, n2, m2, par1[100003], par2[100003];

vector < Edge > edges;

int find (int u, int par[]) {
	if (u == par[u]) return u;
	return par[u] = find(par[u], par);
}

bool join(int u, int v, int par[]) {
	u = find(u, par); v = find(v, par);
	if (u == v) return false;
	par[v] = u;
	return true;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n1 >> m1;
	for (int i = 1; i <= m1; i++) {
		int u, v, c; cin >> u >> v >> c;
		edges.pb(Edge(u, v, c, 1));
	}
	cin >> n2 >> m2;
	for (int i = 1; i <= m2; i++) {
		int u, v, c; cin >> u >> v >> c;
		edges.pb(Edge(u, v, c, 2));
	}
	sort(edges.begin(), edges.end(), [&](Edge &x, Edge &y) {
		return x.c < y.c;
	});
	for (int i = 1; i <= n1; i++) 
		par1[i] = i;
	for (int i = 1; i <= n2; i++)
		par2[i] = i;
	ll res = 0;
	for (auto e : edges) {
		if (n1 == 1 && n2 == 1) break;
		if (e.id == 1) {
			if (!join(e.u, e.v, par1)) continue;
			n1 --;
			res += 1ll * e.c * 1ll * n2;
		}
		else {
			if (!join(e.u, e.v, par2)) continue;
			n2 --;
			res += 1ll * e.c * 1ll * n1;
		}
 	}
 	cout << res;
}