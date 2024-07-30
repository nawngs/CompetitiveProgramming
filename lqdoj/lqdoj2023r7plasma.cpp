#include <bits/stdc++.h>

#define name "plasma"
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

int n;

bool dp[1003][1003][2];

pii a[NMAX + 3];

bool check(pii x, int des, int sign) {
	if (!sign) {
		if (x.fi < 0 && abs(des - x.se) % 2 == 0) return true;
		if (x.fi > 0 && abs(des - x.se) % 2 == 1) return true;
		return false;
	}
	else {
		if (x.fi < 0 && abs(des - x.se) % 2 == 1) return true;
		if (x.fi > 0 && abs(des - x.se) % 2 == 0) return true;
		return false;
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	bool ok = 1;
	for (int i = 1; i <= n; i++) if (a[i].fi + a[n - i + 1].fi != 0) ok = 0;
	if (n % 2 == 0 && ok == 1) {
		for (int i = 1; i <= n / 2; i++) {
			int l = i, r = n - i + 1;
			if ((abs(a[l].se - l) % 2 == 0 && abs(a[r].se - r) % 2 == 0)
			 || (abs(a[l].se - r) % 2 == 1 && abs(a[r].se - l) % 2 == 1)) continue;
			 else  {
			 	cout << "NO" << '\n';
			 	return ;
			 }
		}
		cout << "YES" << '\n';
		return ;
	}
	sort(a + 1, a + n + 1, [&](pii &x, pii &y) {
		return abs(x.fi) > abs(y.fi);
	});
	for (int i = 3; i <= n; i++) if (abs(a[i - 2].fi) == abs(a[i].fi)) {
		cout << "NO" << '\n';
		return ;
	}
	if (n <= 1000) {
		for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++) dp[i][j][0] = dp[i][j][1] = 0;
		dp[0][n + 1][0] = dp[0][n + 1][1] = 1;
		for (int len = n + 1; len >= 2; len--) {
			int i = n + 2 - len;
			for (int l = 0; l <= n + 1 - len; l++) {
				int r = l + len;
				//cout << l << " " << r << " " << dp[l][r][0] << " " << dp[l][r][1] << '\n';
				// if (l == 1 && r == 8) 
					// cout << dp[l][r] << " " << a[i].fi << " " << a[i].se << " " << l + 1 << '\n';
				if ((a[i].fi < 0 && abs(a[i].se - (l + 1)) % 2 == 0)
				  ||(a[i].fi > 0 && abs(a[i].se - (l + 1)) % 2 == 1)) {
				  	dp[l + 1][r][0] |= dp[l][r][1];
				  	if (abs(a[i].fi) != abs(a[i - 1].fi)) dp[l + 1][r][0] |= dp[l][r][0];
				}
				if ((a[i].fi < 0 && abs(a[i].se - (r - 1)) % 2 == 1)
				  ||(a[i].fi > 0 && abs(a[i].se - (r - 1)) % 2 == 0)) {
				  	dp[l][r - 1][1] |= dp[l][r][0];
				  	if (abs(a[i].fi) != abs(a[i - 1].fi)) dp[l][r - 1][1] |= dp[l][r][1];
				}

			}
		}
		for (int i = 0; i <= n; i++) if (dp[i][i + 1][0] || dp[i][i + 1][1]) {
			cout << "YES" << '\n';
			return ;
		}
		cout << "NO" << '\n';
		return ;
	}
	int l = 1, r = n;
	int pos = 1;
	a[n + 1].fi = 0;
	for (int i = 2; i <= n + 1; i++) {
		if (abs(a[i].fi) != abs(a[i - 1].fi)) {
			if (pos != i - 1) {
				if ((check(a[pos], l, 0) && check(a[i - 1], r, 1))
				|| (check(a[pos], r, 1) && check(a[i - 1], l, 0))) l ++, r --;
				else {
					cout << "NO" << '\n';
					return ;
				}
			}
			else {
				if (check(a[pos], l, 0)) l ++;
				else if (check(a[pos], r, 1)) r --;
				else {
					cout << "NO" << '\n';
					return ;
				}
			}
			pos = i;
		}
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}