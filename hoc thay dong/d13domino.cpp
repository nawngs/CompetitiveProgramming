#include <bits/stdc++.h>

#define name ""
#define test "test"
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
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, m, k, a[18][16], ans = 0;

pll dp[20][(1 << 16)];

bool bit(int x, int p) {
	return (x >> p & 1);
}

void minimize(pll &x, const pll &y) {
	x = min(x, y);
}

pll calc(ll x) {
	for (int i = 1; i <= n; i++)
		for (int msk = 0; msk < (1 << m); msk++) 
			dp[i][msk] = {LINF, k + 1};
	pll res = {LINF, k + 1};
	dp[1][0] = {0, 0};
	for (int i = 1; i <= n; i++) { 
		for (int msk = 0; msk < (1 << m); msk++) {
			res = min(res, dp[i][msk]);
			//cout << i << " " << msk << " " << " " << dp[i][msk].fi << " " << dp[i][msk].se << " " << dp[i][msk].fi - x * dp[i][msk].se << '\n';
			if (dp[i][msk].se <= k) {
				ans = min(ans, dp[i][msk].fi - x * dp[i][msk].se);
			}
			for (int j = 0; j < m - 1; j++) 
				if (!bit(msk, j) && !bit(msk, j + 1)) {
					minimize(dp[i][msk ^ (1 << j) ^ (1 << (j + 1))], mp(dp[i][msk].fi - a[i][j] * a[i][j + 1] + x, dp[i][msk].se + 1));
				}
		}
		if (i == n) break;
		for (int j = 0; j < m; j++)
			for (int msk = 0; msk < (1 << m); msk++) 
				if (!bit(msk, j)) minimize(dp[i][msk ^ (1 << j)], dp[i][msk]);
		for (int msk = 0; msk < (1 << m); msk++) {
			pll val = {0, 0};
			for (int j = 0; j < m; j++) 
				if (!bit(msk, j)) val.fi = val.fi - a[i][j] * a[i + 1][j] + x, val.se ++;
			minimize(dp[i + 1][(1 << m) - 1 - msk], mp(dp[i][msk].fi + val.fi, dp[i][msk].se + val.se));
		}
	}
	return res;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	calc(976);
	ll l = 1, r = 1e6, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		pll res = calc(mid);
		if (res.se <= k) r = mid - 1;
		else l = mid + 1;
	}
	cout << -ans;
}