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

ll n, m, a[NMAX + 3], b[NMAX + 3], c[NMAX + 3], d[NMAX + 3];

struct SegmentTree {
	ll it[12 * NMAX + 3];
	void build(int node, int l, int r) {
		it[node] = LINF;
		if (l == r) return ;
		build(lnode); build(rnode);
	}
	void update(int node, int l, int r, int u, ll val) {
		if (u < l || r < u) return ;
		it[node] = min(it[node], val);
		if (l == r) return ;
		update(lnode, u, val); update(rnode, u, val);
	}
	ll query(int node, int l, int r, int u, int v) {
		if (v < l || r < u) return LINF;
		if (u <= l && r <= v) return it[node];
		return min(query(lnode, u, v), query(rnode, u, v));
	}
} it1, it2;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	
	vector < int > compress;
	compress.pb(1); compress.pb(m);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		compress.pb(a[i]);compress.pb(b[i]);compress.pb(c[i]);
	}
	
	sort(compress.begin(), compress.end()); 
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	
	it1.build(1, 1, SZE(compress)); it2.build(1, 1, SZE(compress)); 
	it1.update(1, 1, SZE(compress), 1, 0); it2.update(1, 1, SZE(compress), SZE(compress), 0);

	ll res = LINF;
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(compress.begin(), compress.end(), a[i]) - compress.begin() + 1;
		b[i] = lower_bound(compress.begin(), compress.end(), b[i]) - compress.begin() + 1;
		c[i] = lower_bound(compress.begin(), compress.end(), c[i]) - compress.begin() + 1;
		ll templ = it1.query(1, 1, SZE(compress), a[i], b[i]) + d[i];
		ll tempr = it2.query(1, 1, SZE(compress), a[i], b[i]) + d[i];
		res = min(res, templ + tempr - d[i]);
		it1.update(1, 1, SZE(compress), c[i], templ);
		it2.update(1, 1, SZE(compress), c[i], tempr);
	}
	cout << (res == LINF ? -1 : res);
}