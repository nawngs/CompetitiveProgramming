#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < pii, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[500003], nq, res[500003], last[500003];

pii it[3000003];

piii q[500003];

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = {INF, l};
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	if (it[node * 2].fi < it[node * 2 + 1].fi) it[node] = it[node * 2];
	else it[node] = it[node * 2 + 1];
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node].fi = val;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
	if (it[node * 2].fi < it[node * 2 + 1].fi) it[node] = it[node * 2];
	else it[node] = it[node * 2 + 1];
}

pii query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return {INF, -1};
	if (u <= l && r <= v) return it[node];
	pii lnode = query(node * 2, l, (l + r) / 2, u, v);
	pii rnode = query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
	if (lnode.fi < rnode.fi) return lnode;
	else return rnode;

}

int main() {
	//fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	
	cin >> nq;
	for (int i = 1; i <= nq; i++) {
		cin >> q[i].fi.fi >> q[i].fi.se;
		q[i].se = i;
	}
	sort(q + 1, q + nq + 1, [](piii &x, piii &y) {
		return x.fi.se < y.fi.se;
	});
	build_tree(1, 1, n);
	q[0].fi.se = 0;
	for (int i = 1; i <= nq; i++) {
		for (int j = q[i - 1].fi.se + 1; j <= q[i].fi.se; j++) {
			//cout << j << " " << a[j] << " " << << '\n';
			update(1, 1, n, j, last[a[j]]);
			update(1, 1, n, last[a[j]], INF);
			last[a[j]] = j;
		}
		pii tam = query(1, 1, n, q[i].fi.fi, q[i].fi.se);
		//cout << tam.fi << " " << tam.se << '\n';
		if (tam.fi < q[i].fi.fi) res[q[i].se] = a[tam.se];
	}
	for (int i = 1; i <= nq; i++) cout << res[i] << '\n';
}
