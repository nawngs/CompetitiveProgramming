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

const string NAME = "COVID19";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E16;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Node {
	ll sub, s_minv, minv;
} it[4000003];

ll n, k, q, mu[500003], lazy[4000003], s[500003];

Node merge(Node x, Node y) {
	Node res;
	res.s_minv = 0;
	res.sub = (x.sub + y.sub) % MOD;
	res.minv = min(x.minv, y.minv);
	if (res.minv == x.minv) res.s_minv += x.s_minv;
	if (res.minv == y.minv) res.s_minv += y.s_minv;
	res.s_minv %= MOD;
	return res;
} 

void build(int node, int l, int r) {
	if (l == r) {
		it[node].sub = (-1 * mu[l] + MOD) % MOD;
		it[node].s_minv = mu[l];
		it[node].minv = LINF;
		lazy[node] = LINF;
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
	lazy[node] = LINF;
}

void update(int node, int l, int r) {
	if (lazy[node] != LINF) {
		//cout << l << " " << r << " "<< it[node].sub - MOD << " " << it[node].s_minv << " " << it[node].minv << " " << lazy[node] << '\n';
		if (lazy[node] <= it[node].minv) {
			it[node].sub = ((lazy[node] * (s[r] - s[l - 1]) % MOD) % MOD + MOD) % MOD;
			it[node].s_minv = (s[r] - s[l - 1] + MOD) % MOD;
			it[node].minv = lazy[node];
		}
		else it[node].sub = ((lazy[node] * (s[r] - s[l - 1]) % MOD - it[node].s_minv) % MOD + MOD) % MOD;
		if (l != r) {
			lazy[node * 2] = min(lazy[node * 2], lazy[node]);
			lazy[node * 2 + 1] = min(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = LINF;
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
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

Node query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return {0, 0, LINF};
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return merge(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main() {
	fast;
	//fre();
	int O; cin >> O;
	cin >> n >> k >> q;
	mu[0] = s[0] = 1;
	for (int i = 1; i <= n; i++) {
		mu[i] = (mu[i - 1] * (n + 1)) % MOD;
		s[i] = (s[i - 1] + mu[i]) % MOD;
	}
	build(1, 1, n); 
	for (int i = 1; i <= k; i++) {
		int x; cin >> x;
		update(1, 1, n, x, x, 0);
	}
	cout << it[1].sub << '\n';
	while (q--) {
		char T; 
		ll l, r;
		cin >> T >> l >> r;
		if (T == 'D') {
			Node u = query(1, 1, n, l, l);
			Node v = query(1, 1, n, r, r);
			if (u.minv < v.minv) update(1, 1, n, r, r, u.minv + 1);
			if (v.minv < u.minv) update(1, 1, n, l, l, v.minv + 1);
		}
		else { 
			Node cur = query(1, 1, n, l, r);
			if (cur.minv != LINF) update(1, 1, n, l, r, cur.minv + 1);
		}

		cout << it[1].sub << '\n';
	}
}
