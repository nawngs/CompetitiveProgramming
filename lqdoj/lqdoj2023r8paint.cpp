#include <bits/stdc++.h>

#define name "paint"
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
const int N = 2e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, low, high, a[N + 3], dp[N + 3][N + 3];

bool check(int x) {
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= low; j++) dp[i][j] = INF;
	int cur1 = 1, cur2 = 1;
	for (int i = 1; i <= n; i++) {
		while (a[i] - a[cur1] >= x) cur1 ++;
		while (a[i] - a[cur2] >= 2 * x) cur2 ++;
		for (int j = 0; j <= low; j++) {
			// cout << i << " " << j << " " << dp[i][j] << '\n';
			dp[i][j] = min(dp[i][j], dp[cur2 - 1][j] + 1);
			if (j > 0) dp[i][j] = min(dp[i][j], dp[cur1 - 1][j - 1]);
		}
	}
	for (int j = 0; j <= low; j++) if (dp[n][j] <= high) return true;
	return false;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> low >> high;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//sort(a + 1, a + n + 1);
	if (low + high >= n) {
		cout << 1 << '\n';
		return 0;
	}
	//cout << check(1);
	//return 0;
	int l = 1, r = INF, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}