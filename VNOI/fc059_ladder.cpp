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

int n, a[100003], posl[100003], posr[100003], it[800003], q;

int comp(int val1, int val2) {
	if (val1 == -1) return val2;
	if (val2 == -1) return val1;
	return (a[val1] >= a[val2] ? val1 : val2);
}

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = l;
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = comp(it[node * 2], it[node * 2 + 1]);
} 

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return -1;
	if (u <= l && r <= v) return it[node];
	int lnode = query(node * 2, l, (l + r) / 2, u, v);
	int rnode = query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
	return comp(lnode, rnode);
}

void sol() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build_tree(1, 1, n);
	posl[1] = 1;
	for (int i = 2; i <= n; i++) posl[i] = (a[i] >= a[i - 1] ? posl[i - 1] : i);
	posr[n] = n;
	for (int i = n - 1; i >= 1; i--) posr[i] = (a[i] >= a[i + 1] ? posr[i + 1] : i);
	while (q --) {
		int l, r;
		cin >> l >> r;
		int pos = query(1, 1, n, l, r);
		if (posl[pos] <= l && posr[pos] >= r) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
