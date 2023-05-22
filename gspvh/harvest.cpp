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

const string NAME = "harvest";
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

ll n, m, a[100003], b[100003], dp[100003][2][2][2];


ll bs1(ll pos) {
	ll x = a[pos + 1];
	int l = 1, r = m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (b[mid] < x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

ll bs2(ll pos) {
	ll x = a[pos - 1];
	int l = 1, r = m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (b[mid] > x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void sol() {
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	a[n + 1] = INF;
	a[0] = 0;
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(b + 1, b + m + 1);
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++) dp[i][j][k][0] = dp[i][j][k][1] = INF;
	dp[0][0][0][1] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0][0][1] = min(dp[i - 1][0][1][0]	, dp[i - 1][1][1]);
		int posr = bs2(a[i - 1]);
		int posli = bs1(a[i]);
		if (posr != -1 && posli != -1 && posli >= posr) {
			dp[i][1][0] = min(dp[i - 1][1][0], dp[i - 1][0][0]) 
		}
 		//##############################################################################

		//cout << dp[i][0][0] << " " << dp[i][0][1] << " " << dp[i][1][0] << " " << dp[i][1][1] << '\n';
	}
	cout << min(dp[n][0][1], dp[n][1][1]) << ' ';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (cin >> n >> m && n != 0 && m != 0) sol();
}
