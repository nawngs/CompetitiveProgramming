#include <bits/stdc++.h>

#define name "schedule"
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
const int N = 1E6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m;

struct Job {
	ll k, s, t;
	Job(ll _k = 0, ll _s = 0, ll _t = 0) : k(_k), s(_s), t(_t) {} 
} a[NMAX + 3];

map < int, ll > total;

vector < ll > compress;

namespace sub2 {
	ll it[6 * N], lazy[6 * N];
	
	void build(int node, int l, int r, int x) {
		lazy[node] = -1;
		if (l == r) {
			it[node] = x;
			return ;
		}
		build(lnode, x); build(rnode, x);
		it[node] = it[node * 2] + it[node * 2 + 1];
	}
	
	void update(int node, int l, int r) {
		if (lazy[node] != -1) {
			it[node] = 0;
			if (l != r) 
				lazy[node * 2] = lazy[node * 2 + 1] = 0;
			lazy[node] = -1;
		}
	}
	
	void update(int node, int l, int r, int u, int v) {
		update(node, l, r);
		if (v < l || r < u) return ;
		if (u <= l && r <= v) {
			lazy[node] = 0;
			update(node, l, r);
			return ;
		}
		update(lnode, u, v); update(rnode, u, v);
		it[node] = it[node * 2] + it[node * 2 + 1];
	}
	
	ll query(int node, int l, int r, int u, int v) {
		update(node, l, r);
		if (v < l || r < u) return 0;
		if (u <= l && r <= v) return it[node];
		return query(lnode, u, v) + query(rnode, u, v);
	}
	
	void Minus(int node, int l, int r, int u, int val) {
		it[node] -= val;
		if (l == r) return ;
		int mid = (l + r) / 2;
		if (u <= mid) return Minus(lnode, u, val);
		else return Minus(rnode, u, val);
	}
	
	bool check2(int x) {
		build(1, 1, m, x);
		for (int i = 1; i <= n; i++) {
			int l = a[i].s, r = a[i].t, mid, ans = a[i].s - 1;
			while (l <= r) {
				mid = (l + r) / 2;
				if (query(1, 1, m, a[i].s, mid) < a[i].k) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			if (ans == a[i].t) return false;
			ll temp = query(1, 1, m, a[i].s, ans);
			update(1, 1, m, a[i].s, ans); Minus(1, 1, m, ans + 1, a[i].k - temp);
		}
		return true;
	}
	void solve() {
		int l = 1, r = 250000, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check2(mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout << ans << '\n';
		return ;
	}
}


ll it[12 * NMAX + 3], lazy[12 * NMAX + 3];

void build(int node, int l, int r) {
	lazy[node] = -1;
	if (l == r) {
		it[node] = 0;
		return ;
	}
	build(lnode); build(rnode);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void update(int node, int l, int r) {
	if (lazy[node] != -1) {
		it[node] = lazy[node] * (r - l + 1);
		if (l != r) 
			lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
		lazy[node] = -1;
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
	it[node] = it[node * 2] + it[node * 2 + 1];
}

ll query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(lnode, u, v) + query(rnode, u, v);
}

void Minus(int node, int l, int r, int u, int val) {
	it[node] -= val;
	if (l == r) return ;
	int mid = (l + r) / 2;
	if (u <= mid) return Minus(lnode, u, val);
	else return Minus(rnode, u, val);
}

bool check(ll x) {
	build(1, 1, 2 * n);
	for (int i = 1; i < SZE(compress); i++) 
		update(1, 1, 2 * n, i, i, (compress[i] - compress[i - 1]) * x);
	for (int i = 1; i <= n; i++) {
		int l = a[i].s + 1, r = a[i].t, mid, ans = a[i].s;
		while (l <= r) {
			mid = (l + r) / 2;
			if (query(1, 1, 2 * n, a[i].s + 1, mid) < a[i].k) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (ans == a[i].t) return false;
		ll rem = a[i].k - query(1, 1, 2 * n, a[i].s + 1, ans);
		update(1, 1, 2 * n, a[i].s + 1, ans, 0);
		Minus(1, 1, 2 * n, ans + 1, rem);
	}
	return true;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	bool th = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].k >> a[i].s >> a[i].t;
		th &= (a[i].s == a[i].t);
	}
	if (th) {
		for (int i = 1; i <= n; i++) total[a[i].s] += a[i].k;
		ll ans = 0;
		for (auto x : total) ans = max(ans, x.se);
		cout << ans << '\n';
		return 0;
	}
	sort(a + 1, a + n + 1, [&](Job &x, Job &y) {
		return x.t < y.t;
	});

	if (n <= 500 && m <= N) {
		sub2::solve();
		return 0;
	}
	compress.pb(0);
	for (int i = 1; i <= n; i++) {
		a[i].s --;
		compress.pb(a[i].s), compress.pb(a[i].t);
	}
	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	for (int i = 1; i <= n; i++) {
		a[i].s = lower_bound(compress.begin(), compress.end(), a[i].s) - compress.begin();
		a[i].t = lower_bound(compress.begin(), compress.end(), a[i].t) - compress.begin();
	}
	ll l = 1, r = LINF, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}