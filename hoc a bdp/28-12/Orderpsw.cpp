#include <bits/stdc++.h>

#define name "orderpsw"
#define test "test"
#define ll long long
#define ld long double
#define int ll
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
const ll BLOCK_SIZE = 320;

ll n, k, a[100003], s[100003], frac[100003], it[400003], f[100003], res[300003];

void build(int node, int l, int r) {
	it[node] = (r - l + 1);
	if (l == r) return ;
	int mid = (l + r) / 2;
	build(node * 2, l, mid); build(node * 2 + 1, mid + 1, r);
}	

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || r < pos) return ;
	it[node] += val;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val); update(node * 2 + 1, mid + 1, r, pos, val);
}

struct SegmentTree {
	pll it[400003];
	void build(int node, int l, int r) {
		it[node] = {0, 0};
		if (l == r) return ;
		int mid = (l + r) / 2;
		build(node * 2, l, mid);
		build(node * 2 + 1, mid + 1, r);
	}
	pll merge(const pll &x, const pll &y) {
		pll res;
		res.fi = (x.fi + y.fi) % MOD;
		res.se = (x.se + y.se) % MOD;
		return res;
	}
	void update(int node, int l, int r, int pos, pll val) {
		if (pos < l || r < pos) return ;
		if (l == r) {
			it[node] = val;
			return ;
		}
		int mid = (l + r) / 2;
		update(node * 2, l, mid, pos, val); update(node * 2 + 1, mid + 1, r, pos, val);
		it[node] = merge(it[node * 2], it[node * 2 + 1]);
	}
	pll query(int node, int l, int r, int u, int v) {
		if (v < l || r < u) return {0, 0};
		if (u <= l && r <= v) return it[node];
		int mid = (l + r) / 2;
		return merge(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
	}
} seg;

struct Query {
	int l, r, id;
} Q[300003];

void add(int id) {
	seg.update(1, 1, n, a[id], {frac[n - id], 1});
}

void remove(int id) {
	seg.update(1, 1, n, a[id], {0, 0});
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	cin >> n >> k;
	frac[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		frac[i] = (frac[i - 1] * i) % MOD;
	}
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		s[i] = (s[i - 1] + 1ll * query(1, 1, n, 1, a[i] - 1) * frac[n - i]) % MOD;
		update(1, 1, n, a[i], -1);
	}
	for (int i = n; i >= 1; i--) {
		f[i] = query(1, 1, n, 1, a[i]);
		update(1, 1, n, a[i], 1);
	}
	for (int i = 1; i <= k; i++) {
		cin >> Q[i].l >> Q[i].r;
		if (Q[i].l > Q[i].r) swap(Q[i].l, Q[i].r);
		Q[i].id = i;
	}
	sort(Q + 1, Q + k + 1, [&](Query &x, Query &y) {
		if (x.l / BLOCK_SIZE == y.l / BLOCK_SIZE) return x.r < y.r;
		else return x.l < y.l;
	});
	seg.build(1, 1, n);
	int l = Q[1].l, r = Q[1].r;
	for (int i = l; i <= r; i++) 
		add(i);
	for (int i = 1; i <= k; i++) {
		while (l > Q[i].l) {
			l --;
			add(l);
		}
		while (r < Q[i].r) {
			r ++;
			add(r);
		}
		while (l < Q[i].l) {
			remove(l);
			l ++;
		}
		while (r > Q[i].r) {
			remove(r);
			r --;
		}
		// cout << l << " " << r << " " << Q[i].id << '\n';
		// for (int j = 1; j <= n; j++) cout << j << " " << seg.query(1, 1, n, a[j], a[j]).fi << '\n';
		// cout << "//##############################################################################" << '\n';
		// res[Q[i].id] = s[n];
		// ll &ans = res[Q[i].id];
		// pll temp = seg.query(1, 1, n, a[r] + 1, n); // tong cac so > a[r], so so > a[r] tu l -> r
		// pll temp2 = seg.query(1, 1, n, 1, a[r] - 1); // tong cac so < a[r], so so < a[r] tu l -> r
		// ans = ((ans - f[r] * frac[n - r]) % MOD + MOD) % MOD;
		// ans = (ans - temp.fi + MOD) % MOD;
		// ans = (ans + frac[n - l] * (f[r] + temp2.se)) % MOD;
		// temp = seg.query(1, 1, n, a[l] + 1, n); // tong cac so > a[l], so so > a[l] tu l -> r
		// temp2 = seg.query(1, 1, n, 1, a[l] - 1); // tong cac so < a[l], so so < a[l] tu l -> r
		// ans = ((ans - f[l] * frac[n - l]) % MOD + MOD) % MOD;
		// if (a[r] < a[l]) ans = (ans + frac[n - l]) % MOD;
		// ans = (ans + temp.fi) % MOD;
		// if (a[r] > a[l]) ans = (ans - frac[n - r] + MOD) % MOD;
		// ans = (ans + (f[l] - temp2.se + MOD) * frac[n - r]) % MOD; 
	}
	for (int i = 1; i <= k; i++) cout << (res[i] + 1) % MOD << '\n';
}