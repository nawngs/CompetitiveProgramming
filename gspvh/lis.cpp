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

const string NAME = "lis";
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

ll n, a[220800], f[220800][2], g[220800], dp[220800][2][2];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i][0] = f[i][1] = g[i] = INF;
	}	
	f[0][0] = f[0][1] = g[0] = -INF;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		ll l = 0, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (f[mid][0] < a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		dp[i][0][0] = ans + 1;
		//##############################################################################
		l = 0, r = n;
		while (l <= r) {
			mid = (l + r) / 2;
			if (f[mid][1] < a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		dp[i][0][1] = ans + 1;
		//##############################################################################
		a[i] = -a[i];
		dp[i][1][1] = 1;
		l = 0, r = n;
		while (l <= r) {
			mid = (l + r) / 2;
			if (g[mid] < a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		dp[i][1][1] = max(dp[i][1][1], ans + 1);
		l = 0, r = n;
		while (l <= r) {
			mid = (l + r) / 2;
			if (f[mid][0] < a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		dp[i][1][1] = max(dp[i][1][1], ans + 1);
		//##############################################################################
		//cout << i << " " << g[2] << " " << dp[i][0][0] << " " << dp[i][0][1] << " " << dp[i][1][1] << '\n';
		g[dp[i][0][0]] = min(g[dp[i][0][0]], -a[i]);
		g[dp[i][1][1]] = min(g[dp[i][1][1]], a[i]);
		f[dp[i][1][1]][1] = min(f[dp[i][1][1]][1], a[i]);
		f[dp[i][0][1]][1] = min(f[dp[i][0][1]][1], -a[i]); 
		f[dp[i][0][0]][0] = min(f[dp[i][0][0]][0], -a[i]);
		res = max(res, max(dp[i][0][0], max(dp[i][0][1], dp[i][1][1])));
	}
	cout << res;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
