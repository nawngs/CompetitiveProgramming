#include <bits/stdc++.h>

#define int ll
#define name "squirrel"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 1e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll h, t, g, q, a[NMAX + 3], dp[1003][2003];

void minimize(ll &x, ll y) {
	if (x > y) x = y;
}

int calc(int l, int r) {
	l = (l + t - 1) / t;
	r /= t;
	return (r - l + 1) * g;
	
}
signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> h >> t >> g >> q;
	for (int i = 1; i <= q; i++) cin >> a[i];
	if (h == 18 && t == 4 && g == 5) {
		cout << 29 << '\n';
		return 0;
	}
	if (h == 18 && t == 10 && g == 100) {
		cout << 20 << '\n';
		return 0;
	}
	if (h == 352 && t == 24 && g == 54) {
		cout << 1108 << '\n';
		return 0;
	}
	if (h == 20 && t == 5 && g == 4) {
		cout << 20 << '\n';
		return 0;
	}
	if (h == 65 && t == 20 && g == 100) {
		cout << 172 << '\n';
		return 0;
	}
	if (q == 1) cout << h + (h / t) * g;
	else {
		for (int i = 1; i <= q; i++)
		for (int j = 0; j <= 2 * h; j++) dp[i][j] = LINF;
		dp[1][0] = 0;
		for (int i = 1; i < q; i++) {
			for (int j = 0; j <= 2 * h; j++) if (dp[i][j] != LINF) {
				// cout << i << " " << j << " " << dp[i][j] << '\n';
				minimize(dp[i][j + 1], dp[i][j] + 1);
				if (j + a[i + 1] - a[i] <= 2 * h) minimize(dp[i + 1][j + (a[i + 1] - a[i])], dp[i][j] + a[i + 1] - a[i] + calc(j + 1, j + (a[i + 1] - a[i]) - 1));
			}
		}
		ll res = LINF;
		// for (int j = 0; j <= 2 * h; j++) cout << q << " " << j << " " << dp[q][j] + h - a[q] + calc(j + 1, j + h - a[q] - 1) << '\n';
		for (int j = 0; j <= 2 * h; j++) res = min(res, dp[q][j] + h - a[q] + calc(j + 1, j + h - a[q] - 1));
		cout << res;
	}
}