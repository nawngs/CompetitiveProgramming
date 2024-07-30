#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define plli pair < pll, int >
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
const int N = 1000;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n;

struct Data {
	int d, r, c;
	bool ok = 1;
	Data() {
		d = r = c = 0;
		ok = 0;
	}
	Data(int _d, int _r, int _c, bool _ok) : d(_d), r(_r), c(_c), ok(_ok) {};
} a[3 * N + 3];

pll f[3 * N + 3], tracef[3 * N + 3], traceg[3 * N + 3], maxf[3 * N + 3], maxg[3 * N + 3];

struct SegmentTree {
	plli it[12 * N + 3];
	void build(int node, int l, int r) {
		if (l == r) {
			it[node] = {{0, 0}, l};
			return ;
		}
		build(lnode); build(rnode);
		it[node] = max(it[node * 2], it[node * 2 + 1]);
	}
	void update(int node, int l, int r, int u, pll val) {
		if (u < l || r < u) return ;
		if (l == r) {
			it[node].fi = max(it[node].fi, val);
			return ;
		}
		update(lnode, u, val); update(rnode, u, val);
		it[node] = max(it[node * 2], it[node * 2 + 1]);
	}
	plli query(int node, int l, int r, int u, int v) {
		if (u <= l && r <= v) return it[node];
		if (v <= (l + r) / 2) return query(lnode, u, v);
		if (u > (l + r) / 2) return query(rnode, u, v);
		return max(query(lnode, u, v), query(rnode, u, v));
	}
} treef, treeg;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	vector < int > vec(3);
	int nn = 0;
	vector < int > compress;
	for (int i = 1; i <= n; i++) {
		cin >> vec[0]  >> vec[1] >> vec[2];
		sort(vec.begin(), vec.end());
		a[++ nn] = {vec[2], vec[1], vec[0], 0};
		a[++ nn] = {vec[2], vec[0], vec[1], 1};
		a[++ nn] = {vec[1], vec[0], vec[2], 0};
		compress.pb(vec[0]);
		compress.pb(vec[1]);
		compress.pb(vec[2]);
	}
	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	for (int i = 1; i <= nn; i++) {
		a[i].d = compress.lower_bound(compress.begin(), compress.end(), a[i].d) - compress.begin() + 1;
		a[i].r = compress.lower_bound(compress.begin(), compress.end(), a[i].r) - compress.begin() + 1;
		id[a[i].d].pb(i);
	}
	treef.build(1, 1, 3 * n);
	
}