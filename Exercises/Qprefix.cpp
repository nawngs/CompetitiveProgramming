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

const string NAME = "Qprefix";
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

int n, a[100003], s[100003], it[600003], lazy[600003];

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = s[l];
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r, int u, int v, int val) {
	if (lazy[node] != 0) {
		it[node] += lazy[node];
		if (l != r) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		it[node] += val;
		if (l != r) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	build_tree(1, 1, n);
	int q;
	cin >> q;
	while (q--) {
		int pos, val;
		cin >> pos >> val;
		update(1, 1, n, pos, n, val - a[pos]);
		a[pos] = val;
		cout << it[1] << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
