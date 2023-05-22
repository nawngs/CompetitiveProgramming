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

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const pll MOD = {1e9 + 411, 1e9 + 711};
const ll BASE = 2309;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long r) {
    return l + (rd() % (r - l + 1));
}

int n, q, par[100003];

ll a[100003], a_rev[100003];

pll it1[400003], it2[400003], pw[100003];

set < int > ms[100003];

map < int, int > used;

pll mul(const pll &x, const ll &y) {
	pll res;
	res.fi = (x.fi * y) % MOD.fi;
	res.se = (x.se * y) % MOD.se;
	return res;
}

pll operator + (const pll &x, const pll &y) {
	pll res;
	res.fi = (x.fi + y.fi) % MOD.fi;
	res.se = (x.se + y.se) % MOD.se;
	return res;
}

bool operator != (const pll &x, const pll &y) {
	return (x.fi != y.fi) || (x.se != y.se);
}

struct SegmentTree {
	pll it[400003];
	void build(int node, int l, int r, ll a[]) {
		if (l == r) {
			it[node] = mul(pw[l], a[l]);
			return ;
		}
		int mid = (l + r) / 2;
		build(node * 2, l, mid, a); build(node * 2 + 1, mid + 1, r, a);
		it[node] = it[node * 2] + it[node * 2 + 1];
	}

	pll query(int node, int l, int r, int u, int v) {
		if (v < l || r < u) return mp(0, 0);
		if (u <= l && r <= v) return it[node];
		int mid = (l + r) / 2;
		return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
	}

	void update(int node, int l, int r, int pos, int val) {
		if (pos < l || pos > r) return ;
		if (l == r) {
			it[node] = mul(pw[l], val);	
			return ;
		}
		int mid = (l + r) / 2;
		update(node * 2, l, mid, pos, val); update(node * 2 + 1, mid + 1, r, pos, val);
		it[node] = it[node * 2] + it[node * 2 + 1];
	}
} seg, seg_rev;

int find(int u) {
	if (u == par[u]) return u;
	return par[u] = find(par[u]);
}

void join(int u, int v) {
	v = n - v + 1;
	u = find(u); v = find(v);
	if (u == v) return ;
	if (sz(ms[u]) < sz(ms[v])) swap(u, v);
	for (auto x : ms[v]) {
		seg.update(1, 1, n, x, a[u]);
		seg_rev.update(1, 1, n, n - x + 1, a[u]);
		a[x] = a[u];
		a_rev[n - x + 1] = a[u];
		ms[u].insert(x);
	}
	par[v] = u;
}

bool check(int l1, int r1, int l2, int r2) {
	pll hash1 = seg.query(1, 1, n, l1, r1), hash2 = seg_rev.query(1, 1, n, l2, r2);
	if (l1 < l2) {
		hash1.fi = (hash1.fi * pw[l2 - l1].fi) % MOD.fi;
		hash1.se = (hash1.se * pw[l2 - l1].se) % MOD.se;
	}
	else {
		hash2.fi = (hash2.fi * pw[l1 - l2].fi) % MOD.fi;
		hash2.se = (hash2.se * pw[l1 - l2].se) % MOD.se;
	}
	return (hash1 != hash2);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	pw[0] = {1, 1};
	for (int i = 1; i <= n; i++) {
		par[i] = i; ms[i].insert(i);
		pw[i].fi = (pw[i - 1].fi * BASE) % MOD.fi;
		pw[i].se = (pw[i - 1].se * BASE) % MOD.se;
	}
	for (int i = 1; i <= n; i++) {
		while (1) {
			a[i] = get_random(1, INF);
			if (used[a[i]]) continue;
			used[a[i]] = 1;
			break;
		}
		a_rev[n - i + 1] = a[i];
	}
	seg.build(1, 1, n, a);
	seg_rev.build(1, 1, n, a_rev);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l1, l2; cin >> l1 >> l2;
			int r1 = (l1 + l2) / 2, r2 = r1 + ((l1 + l2) % 2 == 0);
			l2 = (n - l2 + 1); r2 = (n - r2 + 1);
			while (l1 <= r1) {
				int l = 1, r = r1 - l1 + 1, mid, ans = -1;
				while (l <= r) {
					mid = (l + r) / 2;
					if (check(l1, l1 + mid - 1, l2, l2 + mid - 1)) {
						ans = mid;
						r = mid - 1;
					}
					else l = mid + 1;
				}
				if (ans == -1) break;
				join(l1 + ans - 1, l2 + ans - 1);
				l1 += ans; l2 += ans;
			}
		}
		else {
			int a, b, x, y; cin >> a >> b >> x >> y;
			if (a > x) {
				swap(a, x);
				swap(b, y);
			}
			if (b - a != y - x) cout << 1 << '\n';
			else {
				pll temp1 = seg.query(1, 1, n, a, b), temp2 = seg.query(1, 1, n, x, y);
				temp1.fi = (temp1.fi * pw[x - a].fi) % MOD.fi;
				temp1.se = (temp1.se * pw[x - a].se) % MOD.se;
				if (temp1 != temp2) cout << 2 << '\n';
				else cout << 0 << '\n';
			}
		}
		// for (int i = 1; i <= n; i++) 
		// 	cout << i << " " << a[i] << " " << seg.query(1, 1, n, i, i).fi << " " << seg_rev.query(1, 1, n, n - i + 1, n - i + 1).fi << '\n';
	}
}