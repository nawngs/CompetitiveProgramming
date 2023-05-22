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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[100003], it[800003], lazy[800003], d, q;

ll s = 0;

void build(int node, int l, int r) {
	if (l == r) {
		it[node] = a[l];
		return ;
	}
	build(node * 2, l, (l + r) / 2);
	build(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

void update_node(int node, int l, int r) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int l, int r, int u, int v) {
	update_node(node, l, r);
	if (r < u || v < l) return ;
	if (u <= l && r <= v) {
		lazy[node] = -1;
		update_node(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v);
	update(node * 2 + 1, mid + 1, r, u, v);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

int main() {
	fast;
	cin >> n >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += 1ll * a[i];
	}
	build(1, 1, n);
	cout << max(1ll * it[1], (s + 1ll * d - 1) / (1ll * d)) << '\n';
	int i = 0;
	while (q --) { 	
		int l, r;
		cin >> l >> r;
		s -= 1ll * (r - l + 1);
		update(1, 1, n, l, r);
		cout << max(1ll * it[1], (s + 1ll * d - 1) / (1ll * d)) + (++ i) << '\n';
	}
}
