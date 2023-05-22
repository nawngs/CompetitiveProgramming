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

int n, dp[100003], pos[100003], gt[100003];

pii a[100003], it[400003];

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node].se += val;
		it[node].fi += val * gt[l];
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node].fi = it[node * 2].fi + it[node * 2 + 1].fi;
	it[node].se = it[node * 2].se + it[node * 2 + 1].se;
}

int query(int node, int l, int r, int val) {
	if (l > r) return -LINF;
	int mid = (l + r) / 2;
	if (it[node].se == val) return it[node].fi;
	if (it[node * 2].se >= val) return query(node * 2, l, mid, val);
	else return it[node * 2].fi + query(node * 2 + 1, mid + 1, r, val - it[node * 2].se);

}

void solve(int l, int r, int x, int y) {
	if (r < l) return ;
	int mid = (l + r) / 2;
	for (int i = x; i <= y; i++) {
		update(1, 1, n, a[i].se, 1);
		if (i >= mid) {
			int tam = query(1, 1, n, mid);
			if (dp[mid] > tam + a[i].fi) {
				dp[mid] = tam + a[i].fi;
				pos[mid] = i;
			}
		}
	}
	for (int i = x; i <= y; i++) update(1, 1, n, a[i].se, -1);
	solve(l, mid - 1, x, pos[mid]);
	for (int i = x; i < pos[mid]; i++) update(1, 1, n, a[i].se, 1);
	solve(mid + 1, r, pos[mid], y);
	for (int i = x; i < pos[mid]; i++) update(1, 1, n, a[i].se, -1);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) dp[i] = LINF;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, [&](pii &x, pii &y) {
		return x.se < y.se;
	});
	for (int i = 1; i <= n; i++) {
		gt[i] = a[i].se;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	solve(1, n, 1, n);
	int m;
	cin >> m;
	while (m--) {
		int x;
		cin >> x;
		int l = 0, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (dp[mid] <= x) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		cout << ans << ' ';
	}
}

signed main() {
	//fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
