#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, par[NMAX + 3], sze[NMAX + 3];

ll lazy[6 * NMAX + 3], f[NMAX + 3];

int edge[NMAX + 3];

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;
	if (sze[u] < sze[v]) swap(u, v);
	par[v] = u; sze[u] += sze[v]; sze[v] = 0;
	return true; 
}

struct Update {
	int l, r, w;
	Update() {
		l = r = w = 0;
	}
	Update(int _l, int _r, int _w) : l(_l), r(_r), w(_w) {};
};

vector < Update > upds[NMAX + 3];

struct Node {
	pll val1, val2;
	Node() {
		val1 = val2 = mp(-1, -1);
	}
} it[6 * NMAX + 3];

Node merge(const Node &x, const Node &y) {
	Node res;
	if (x.val1.se == y.val1.se) {
		res.val1 = min(x.val1, y.val1);
		res.val2 = min(x.val2, y.val2);
	}
	else {
		if (x.val1.fi < y.val1.fi) {
			res.val1 = x.val1;
			res.val2 = min(x.val2, y.val1);
		}
		else {
			res.val1 = y.val1;
			res.val2 = min(y.val2, x.val1);
		}
	}
	return res;
}

void build(int node, int l, int r) {
	lazy[node] = 0;
	if (l == r) {
		it[node].val1 = {0, find(l)};
		it[node].val2 = {LINF, -1};
		return ;
	}
	build(lnode); build(rnode);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node].val1.fi += lazy[node];
		it[node].val2.fi += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, ll val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		// cout << "wowo " << l << " " << r << " " << it[node].val1.fi << " " << it[node].val1.se << '\n';	
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
	//cout << it[node].val1.fi << " " << it[node].val1.se << '\n';	
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		int mini, maxi, minj, maxj, w;
		cin >> mini >> maxi >> minj >> maxj >> w;
		upds[mini].pb({minj, maxj, w});
		upds[maxi + 1].pb({minj, maxj, -w});
		upds[minj].pb({mini, maxi, w});
		upds[maxj + 1].pb({mini, maxi, -w});
	}
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sze[i] = 1;
	}
	ll res = 0;
	while (sze[find(1)] != n) {
		build(1, 1, n);
		for (int i = 1; i <= n; i++) {
			f[i] = LINF;
			edge[i] = -1;
		}
		for (int i = 1; i <= n; i++) {
			for (auto x : upds[i]) update(1, 1, n, x.l, x.r, x.w);
			int u = find(i);
			if (it[1].val1.se != u) {
				if (f[u] > it[1].val1.fi) {
					f[u] = it[1].val1.fi;
					edge[u] = it[1].val1.se;
				}
			}
			else {
				if (f[u] > it[1].val2.fi) {
					f[u] = it[1].val2.fi;
					edge[u] = it[1].val2.se;
				}
			}
		}
		for (int i = 1; i <= n; i++) if (i == find(i) && edge[i] != -1) 
			if (merge(i, edge[i])) res += f[i];

	}
	cout << res;
}
