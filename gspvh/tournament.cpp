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

const string NAME = "tournament";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, l[300003], r[300003], w[300003], it[1500003], lazy[1500003];

void update(int node, int l, int r, int u, int v, int val) {
	//cout << node << " " << l << " " << r << " " << u << " " << v << " " << val << '\n';
	if (lazy[node] != 0) {
		it[node] = lazy[node] * (r - l + 1);
		if (l != r) lazy[node * 2] = lazy[node * 2 + 1] = lazy[node]; 
		lazy[node] = 0;
	}
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		it[node] = val * (r - l + 1);
		if (l != r) lazy[node * 2] = lazy[node * 2 + 1] = val;
		return ;
	}
	update(node * 2, l, (l + r) / 2, u, v, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, u, v, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int query(int node, int l, int r, int u, int v) {
	if (lazy[node] != 0) {
		it[node] = lazy[node] * (r - l + 1);
		if (l != r) lazy[node * 2] = lazy[node * 2 + 1] = lazy[node]; 
		lazy[node] = 0;
	}
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(node * 2, l, (l + r) / 2, u, v) + query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> l[i] >> r[i] >> w[i];	
	for (int i = m; i >= 1; i--) {
		if (w[i] != l[i]) update(1, 1, n, l[i], w[i] - 1, w[i]);
		if (w[i] != r[i]) update(1, 1, n, w[i] + 1, r[i], w[i]);
	}
	for (int i = 1; i <= n; i++) cout << query(1, 1, n, i, i) << ' ';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	sol();
}
