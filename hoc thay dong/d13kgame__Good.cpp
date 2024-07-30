#include <bits/stdc++.h>

#define name ""
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
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 5000;

int n, k, dp[N + 3][103], f[BASE + 3];

int solve(int i, int j) {
	cout << i << " " << j << '\n';
	if (i == 0 || (i == 1 && j == 1)) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	for (int t = 1; t <= k; t++) if (i >= t && t != j) {
		if (!solve(i - t, t)) return dp[i][j] = 1;
	}
	return dp[i][j] = 0;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	memset(dp, 255, sizeof(dp));
	cin >> n >> k;
	cout << solve(n, k) << '\n';
}
