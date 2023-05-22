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

ll n, a[200003], it[1200003];

pll lazy[1200003];

void calc(ll index, ll l, ll r, pll a) {
	ll tam = (r + l) * (r - l + 1) / 2;
	tam *= a.fi;
	it[index] += tam - (r - l + 1) * a.se;
}

void sum_pair(pll &a, pll b) {
	a.fi += b.fi;
	a.se += b.se;
}

void build(ll node, ll l, ll r) {
	if (l == r) {
		it[node] = a[l];
		return ;
	}
	build(node * 2, l, (l + r) / 2);
	build(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void update(ll node, ll l, ll r, ll u, ll v) {
	if (lazy[node].fi != 0) {
		calc(node, l, r, lazy[node]);
		if (l != r) {
			sum_pair(lazy[node * 2], lazy[node]);
			sum_pair(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = {0, 0};
	}
	if (r < u || v < l) return ;
	if (u <= l && r <= v) {
		calc(node, l, r, {1, u - 1});
		if (l != r) {
			sum_pair(lazy[node * 2], {1, u - 1});
			sum_pair(lazy[node * 2 + 1], {1, u - 1});
		}
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, u, v);
	update(node * 2 + 1, mid + 1, r, u, v);
	it[node] = it[node * 2] + it[node * 2 + 1];
} 

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return 0;
	if (lazy[node].fi != 0) {
		calc(node, l, r, lazy[node]);
		if (l != r) {
			sum_pair(lazy[node * 2], lazy[node]);
			sum_pair(lazy[node * 2 + 1], lazy[node]);
		}
		lazy[node] = {0, 0};
	}
	if (u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	int q;
	cin >> q;
	while (q --) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1) update(1, 1, n, l, r);
		else cout << query(1, 1, n, l, r) << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
