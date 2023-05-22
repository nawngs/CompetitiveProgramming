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

int n, l, r, a[100003], it[600003];

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = a[l];
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return MOD;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query(node * 2, l, (l + r) / 2, u, v), query(node * 2 + 1, (l + r) / 2 + 1, r, u, v));
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build_tree(1, 1, n);
	int q;
	cin >> q;
	while (q --) {
		int l, r;
		cin >> l >> r;
		cout << query(1, 1, n, l, r) << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
