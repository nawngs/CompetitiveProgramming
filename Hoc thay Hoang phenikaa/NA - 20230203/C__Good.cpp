#include <bits/stdc++.h>

#define name ""
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

int dp[103][103][103], n, a[103];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				if (dp[i][j][k] == 0) continue;
				dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
				if (a[i + 1] == j || a[i + 1] == k) continue;
				dp[i + 1][k][a[i + 1]] = max(dp[i + 1][k][a[i + 1]], dp[i][j][k] + 1);
			}
		}
	}
	int res = 0;
	for (int j = 0; j <= n; j++)
		for (int k = 0; k <= n; k++) res = max(res, dp[n][j][k]);
	cout << res - 1 << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}