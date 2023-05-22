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
const int BLOCK_SIZE = 320;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Query {
	int l, r, id;
} querys[100003];

int n, a[100003], q, it[400003];

ll res[100003], ans = 0;

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] += val;
	if (l == r) return ;
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(node * 2, l, (l + r) / 2, u, v) + query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
}

void add(int i, int type) {
	if (type == 1) ans += query(1, 0, n, a[i] + 1, n);
	else ans += query(1, 0, n, 0, a[i] - 1);
	update(1, 0, n, a[i], 1);
}

void cut(int i, int type) {
	if (type == 1) ans -= query(1, 0, n, a[i] + 1, n);
	else ans -= query(1, 0, n, 0, a[i] - 1);
	update(1, 0, n, a[i], -1);
}

int main() {
	fast;
	cin >> n >> q;
	vector < int > val;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		val.push_back(a[i]);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	for (int i = 1; i <= n; i++) a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
	for (int i = 1; i <= q; i++) {
		cin >> querys[i].l >> querys[i].r;
		querys[i].l ++;
		querys[i].id = i;
	}
	sort(querys + 1, querys + q + 1, [&](Query &x, Query &y) {
		return (x.l / BLOCK_SIZE == y.l / BLOCK_SIZE ? x.r < y.r : x.l < y.l);
	});
	int curl = querys[1].l, curr = querys[1].r;
	for (int i = querys[1].l; i <= querys[1].r; i++) add(i, 1);
	for (int i = 1; i <= q; i++) {
		int l = querys[i].l, r = querys[i].r;
		while (curr < r) add(++curr, 1);
		while (curr > r) cut(curr--, 1);
		while (curl < l) cut(curl++, 0);
		while (curl > l) add(--curl, 0);
		res[querys[i].id] = ans;
	}
	for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}