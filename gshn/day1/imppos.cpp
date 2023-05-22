#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
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
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, k, dem = 0;

pii a[100007], dp[100007], dp2[100007];

pii it[1600100];

void roi_rac() {
	vector < piii > f;
	for (int i = 1; i <= k; i++) {
		f.push_back({a[i].fi, {i, 1}});
		f.push_back({a[i].se, {i, 2}});
	}
	sort(f.begin(), f.end());
	dem = 0;
	for (int i = 0; i < f.size(); i++) {
		dem += (i == 0 || f[i].fi != f[i - 1].fi);
		if (f[i].se.se == 1) a[f[i].se.fi].fi = dem;
		else a[f[i].se.fi].se = dem;
	}
}

pii merge(const pii &x, const pii &y) {
	if (x.fi == y.fi) return {x.fi, x.se + y.se};
	return (x.fi > y.fi ? x : y);
}

void update(int node, int l, int r, int pos, pii val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = merge(it[node], val);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = merge(it[node * 2], it[node * 2 + 1]);
}

pii query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return {0, 0};
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return merge(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void build_tree(int node, int l, int r) {
	it[node] = {0, 0};
	if (l == r) return ;
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
}

main() {
	fast;
	//fre();
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) cin >> a[i].fi >> a[i].se;
	a[++k] = {1, 1};
	a[++k] = {n, m};
	roi_rac();
	sort(a + 1, a + k + 1, [&](pii &x, pii &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
	});
	build_tree(1, 1, dem);
	dp[1] = {1, 1};
	update(1, 1, dem, a[1].se, dp[1]);
	for (int i = 2; i <= k; i++) {
		dp[i] = query(1, 1, dem, 1, a[i].se);
		dp[i].fi += 1;
		if (dp[i].fi == 1) dp[i].se = 1;
		update(1, 1, dem, a[i].se, dp[i]);
	}
	build_tree(1, 1, dem);	
	reverse(a + 1, a + k + 1);
	dp2[1] = {1, 1};
	update(1, 1, dem, a[1].se, dp2[1]);
	for (int i = 2; i <= k; i++) {
		dp2[i] = query(1, 1, dem, a[i].se, dem);
		dp2[i].fi += 1;
		if (dp2[i].fi == 1) dp2[i].se = 1;
		update(1, 1, dem, a[i].se, dp2[i]);
	}
	int res = 0;
	for (int i = 2; i < k; i++) 
		if (dp2[i].fi + dp[k - i + 1].fi == dp2[k].fi + 1 && dp2[i].se * dp[k - i + 1].se == dp2[k].se) res ++;
	cout << res;
}
