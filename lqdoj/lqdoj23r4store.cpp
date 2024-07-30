#include <bits/stdc++.h>

#define name "store"
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
const int NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, a[NMAX + 3], lazy[6 * NMAX + 3], q;

pll it[6 * NMAX + 3];

void build(int node, int l, int r) {
	lazy[node] = 0;
	if (l == r) {
		it[node] = {a[l], a[l]};
		return ;
	}
	build(lnode); build(rnode);
	it[node].fi = it[node * 2].fi + it[node * 2 + 1].fi;
	it[node].se = it[node * 2 + 1].se;
}

void update(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node].fi = 1ll * (r - l + 1) * lazy[node];
		it[node].se = lazy[node];
		if (l != r) lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v, ll val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] = val;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
	it[node].fi = it[node * 2].fi + it[node * 2 + 1].fi;
	it[node].se = it[node * 2 + 1].se;
}

ll query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node].fi;
	return query(lnode, u, v) + query(rnode, u, v);
}

int walk1(int node, int l, int r, int st, ll rem) {
	if (it[node].se > rem) return -1;
	if (l == r) return l;
	update(lnode); update(rnode);
	if (st > (l + r) / 2) return walk1(rnode, st, rem);
	if (it[node * 2].se <= rem) return walk1(lnode, st, rem);
	else return walk1(rnode, st, rem);
}

int walk2(int node, int l, int r, ll rem) {
	if (l == r) return (rem >= it[node].fi);
	update(lnode); update(rnode);
	if (it[node * 2].fi >= rem) return walk2(lnode, rem);
	else return (l + r) / 2 - l + 1 + walk2(rnode, rem - it[node * 2].fi);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	cin >> q;
	while (q--) {
		ll t, x, y; cin >> t >> x >> y;
		if (t == 1) {
			int l = 1, r = x, mid, ans = x + 1;
			while (l <= r) {
				mid = (l + r) / 2;
				if (query(1, 1, n, mid, mid) <= y) {
					ans = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			update(1, 1, n, ans, x, y);
		}
		else {
			int cur = x, res = 0;
			while (cur <= n) {
				int ans = walk1(1, 1, n, cur, y);
				if (ans == -1) break;
				cur = ans - 1;
				ans = walk2(1, 1, n, query(1, 1, n, 1, cur) + y);
				res += ans - cur;
				y -= query(1, 1, n, cur + 1, ans);
				cur = ans + 1;
			}
			cout << res << '\n';
		}
	}
}