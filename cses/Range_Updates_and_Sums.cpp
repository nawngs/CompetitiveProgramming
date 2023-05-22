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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, q, a[200003], it[1200003];
pll lazy[1200003];

void build_tree(ll node, ll l, ll r) {
	if (l == r) {
		it[node] = a[l];
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void change_node(ll node, ll l, ll r, pll val) {
	if (val.se == 1) it[node] += (r - l + 1) * val.fi;
	else it[node] = (r - l + 1) * val.fi;
}

void update(ll node, ll l, ll r, ll u, ll v, pll val) {
	if (lazy[node].se != 0) {
		change_node(node, l, r, lazy[node]);
		if (l != r) {
			if (lazy[node].se == 2) lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
			else {
				lazy[node* 2].fi += lazy[node].fi;
				lazy[node * 2 + 1].fi += lazy[node].fi;
				if (lazy[node * 2].se == 0) lazy[node * 2].se = 1;
				if (lazy[node * 2 + 1].se == 0) lazy[node * 2 + 1].se = 1;  
			}
			lazy[node] = {0, 0};
		}
	}
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		change_node(node, l, r, val);
		if (l != r) {
			if (val.se == 2) lazy[node * 2] = lazy[node * 2 + 1] = val;
			else {
				lazy[node* 2].fi += val.fi;
				lazy[node * 2 + 1].fi += val.fi;
				if (lazy[node * 2].se == 0) lazy[node * 2].se = 1;
				if (lazy[node * 2 + 1].se == 0) lazy[node * 2 + 1].se = 1;  
			}
		}
		return ;

	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (lazy[node].se != 0) {
		change_node(node, l, r, lazy[node]);
		if (l != r) {
			if (lazy[node].se == 2) lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
			else {
				lazy[node* 2].fi += lazy[node].fi;
				lazy[node * 2 + 1].fi += lazy[node].fi;
				if (lazy[node * 2].se == 0) lazy[node * 2].se = 1;
				if (lazy[node * 2 + 1].se == 0) lazy[node * 2 + 1].se = 1;  
			}
			lazy[node] = {0, 0};
		}
	}
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void sol() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build_tree(1, 1, n);
	while (q--) {
		ll type, l, r;
		cin >> type >> l >> r;
		if (type == 1 || type == 2) {
			ll x;
			cin >> x;
			update(1, 1, n, l, r, {x, type});
		}
		else cout << query(1, 1, n, l, r) << '\n';
	}
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
