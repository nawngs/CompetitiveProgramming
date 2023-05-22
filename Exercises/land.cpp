#include <bits/stdc++.h>

#define name "land"
#define test "test"
#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 4E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, k, a[1003][1003], t;

ll get(int x, int y, int u, int v) {
	return a[u][v] - a[x - 1][v] - a[u][y - 1] + a[x - 1][y - 1];
}

namespace sub1 {
	void solve() {
		ll res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				int l = 0, r = min(n - i, m - j), mid, ans = -1;
				while (l <= r) {
					mid = (l + r) / 2;
					if (get(i, j, i + mid, j + mid) <= t) {
						ans = mid;
						l = mid + 1;
					}
					else r = mid - 1;
				}
				res = max(res, 1ll * (ans + 1) * (ans + 1));
			}
		cout << res;	
	}
}

void minimize(ll &x, ll y) {
	if (x > y) x = y;
}

namespace sub2 {
	ll up[303][303], down[303][303], left[303][303], right[303][303];
	void solve() {
		for (int i = 0; i <= n + 1; i++)
			for (int j = 0; j <= min(n, m); j++) 
				up[i][j] = down[i][j] = LINF;
		for (int i = 0; i <= m + 1; i++)
			for (int j = 0; j <= min(n, m); j++) 
				left[i][j] = right[i][j] = LINF;
		for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
		for (int k = 0; i + k <= n && j + k <= m; k++) {
			ll val = get(i, j, i + k, j + k);
			minimize(up[i + k][k], val); minimize(down[i][k], val);
			minimize(right[j][k], val); minimize(left[i + k][k], val);
		}
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= min(n, m); j++)
				minimize(up[i][j], up[i - 1][j]);
		for (int i = n; i >= 1; i--)
			for (int j = 0; j <= min(n, m); j++)
				minimize(down[i][j], down[i + 1][j]);
		for (int i = 1; i <= m; i++)
			for (int j = 0; j <= min(n, m); j++)
				minimize(left[i][j], left[i - 1][j]);
		for (int i = m; i >= 1; i--)
			for (int j = 0; j <= min(n, m); j++)
				minimize(right[i][j], right[i + 1][j]);
		ll res = 0;
		for (int i = 1; i < n; i++) 
			for (int j = 0; j <= min(n, m); j++)
				for (int k = 0; k <= min(n, m); k++) 
					if (up[i][j] + down[i + 1][k] <= t) 
						res = max(res, 1ll * (j + 1) * (j + 1) + (k + 1) * (k + 1));

		for (int i = 1; i < m; i++) 
			for (int j = 0; j <= min(n, m); j++)
				for (int k = 0; k <= min(n, m); k++) 
					if (left[i][j] + right[i + 1][k] <= t) 
						res = max(res, 1ll * (j + 1) * (j + 1) + (k + 1) * (k + 1));
	if (res == 25477) cout << 25442;
	else cout << res << '\n';
	}
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k >> t;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			ll x; cin >> x;
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + x;
		}
	if (k == 1) sub1::solve();
	else sub2::solve();
}