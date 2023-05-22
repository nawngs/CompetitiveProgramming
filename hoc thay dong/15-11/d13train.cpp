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

int n, m, c, it[1600003], lazy[1600003];

pii a[100003];

vector < int > roi_rac;

void update(int node, int l, int r) {
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
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		lazy[node] ++;
		update(node, l, r);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v);
	update(node * 2 + 1, mid + 1, r, u, v);
	it[node] = max(it[node * 2], it[node * 2 + 1]);
}

int query(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return -INF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main() {
	fast;
	//fre();
	cin >> n >> c >> m; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		a[i].se --;
		roi_rac.push_back(a[i].fi);
		roi_rac.push_back(a[i].se);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= n; i++) {
		a[i].fi = lower_bound(roi_rac.begin(), roi_rac.end(), a[i].fi) - roi_rac.begin() + 1;
		a[i].se = lower_bound(roi_rac.begin(), roi_rac.end(), a[i].se) - roi_rac.begin() + 1;
	}
	int res = 0;
	sort(a + 1, a + n + 1, [&](pii &x, pii &y) {
		return (x.se < y.se) || (x.se == y.se && x.fi > y.fi);
	});
	for (int i = 1; i <= n; i++) {
		if (query(1, 1, 2 * n, a[i].fi, a[i].se) == c) continue;
		res ++;
		update(1, 1, 2 * n, a[i].fi, a[i].se);
	}
	cout << res;
}
