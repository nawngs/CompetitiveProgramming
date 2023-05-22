#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[200003], it[1200003], lazy[1200003], q, s[200003];

void build_tree(ll node, ll l, ll r) {
	if (l == r) {
		it[node] = s[l];
		return ;
	}
	ll mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

void update(ll node, ll l, ll r, ll u, ll v, ll val) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l < r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		it[node] += val;
		if (l < r) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return -INF;
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l < r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void sol() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	build_tree(1, 0, n);
	while (q --) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1) {
			int tam = z - a[y];
			a[y] = z;
			update(1, 0, n, y, n, tam);
		}
		else cout << max(1ll * 0, query(1, 0, n, y, z) - query(1, 0, n, y - 1, y - 1)) << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
