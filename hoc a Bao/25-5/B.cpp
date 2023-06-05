#include <bits/stdc++.h>
 
#define int ll
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, f[200003];

pii it[1600003];

pii a[200003];

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node].fi;
	return max(query(lnode, u, v), query(rnode, u, v));
}

void MAX(pii &x, const pii &y) {
	x.fi = max(x.fi, y.fi);
	x.se = max(x.se, y.se);
}

void update(int node, int l, int r, int pos, pii val) {
	if (pos < l || pos > r) return ;
	MAX(it[node], val);
	if (l == r) return ;
	update(lnode, pos, val); update(rnode, pos, val);
}

int query2(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return -INF;
	if (u <= l && r <= v) return it[node].se;
	return max(query2(lnode, u, v), query2(rnode, u, v));
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	vector < int > val;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		val.pb(a[i].fi), val.pb(a[i].se);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for (int i = 1; i <= n; i++) {
		a[i].fi = lower_bound(val.begin(), val.end(), a[i].fi) - val.begin() + 1;
		a[i].se = lower_bound(val.begin(), val.end(), a[i].se) - val.begin() + 1;
	}
	for (int i = 1; i <= 8 * n; i++) it[i] = {0, -INF};
	// for (int i = 1; i <= n; i++) cout << a[i].fi << " " << a[i].se << '\n';
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int temp = query(1, 1, 2 * n, 1, a[i].fi - 1) + (val[a[i].se - 1] - val[a[i].fi - 1] + 1);
		temp = max(temp, query2(1, 1, 2 * n, a[i].fi, a[i].se) + val[a[i].se - 1]);
		res = max(res, temp); update(1, 1, 2 * n, a[i].se, {temp, temp - val[a[i].se - 1]});
	}
	cout << res;
}