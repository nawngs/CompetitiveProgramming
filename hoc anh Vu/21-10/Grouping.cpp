#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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
const ll LINF = 1E16;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, r, a[100003];

pll it[800003];

vector < ll > roi_rac;

int get_val(ll x) {
	return lower_bound(roi_rac.begin(), roi_rac.end(), x) - roi_rac.begin() + 1;
}

void build_tree(int node, int l, int r) {
	it[node] = {0, 0};
	if (l == r) return ;
	int mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
}

void update(int node, int l, int r, int pos, ll val) {
	if (pos < l || pos > r) return;
	it[node].fi += val;
	it[node].se ++;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

ll get_sum(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node].fi;
	int mid = (l + r) / 2;
	return get_sum(node * 2, l, mid, u, v) + get_sum(node * 2 + 1, mid + 1, r, u, v);
}

ll get_cnt(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node].se;
	int mid = (l + r) / 2;
	return get_cnt(node * 2, l, mid, u, v) + get_cnt(node * 2 + 1, mid + 1, r, u, v);
}

void sol() {
	cin >> n >> k >> r;
	roi_rac.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		roi_rac.push_back(a[i]);
		roi_rac.push_back(a[i] - 1);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	build_tree(1, 1, 2 * n);
	for (int i = 1; i <= r; i++)
		update(1, 1, 2 * n, get_val(a[i]), a[i]);
	for (int i = r + 1; i <= n; i++) {
		update(1, 1, 2 * n, get_val(a[i]), a[i]);
		ll l = 0, r = LINF, ans, mid;
		while (l <= r) {
			mid = (l + r) / 2;
			ll val = get_val(mid);
			ll s = get_sum(1, 1, 2 * n, 1, val) + (i - get_cnt(1, 1, 2 * n, 1, val)) * mid;
			if (s >= k * mid) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << ans << '\n';
	}
}

main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
