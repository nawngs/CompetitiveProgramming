#include <bits/stdc++.h>

#define name "sortwood"
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

ll n;

pll a[5003];

ll dp[5003][5003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, [&](pll &x, pll &y) {
		return x.fi + x.se < y.fi + y.se;
	});
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= n; j++) dp[i][j] = LINF;
	dp[0][0] = 0;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if (dp[i - 1][j - 1] <= a[i].fi) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i].se);
			if (dp[i][j] != LINF) res = max(res, 1ll * j);
		}
	}
	cout << res;
}