#include <bits/stdc++.h>

#define name "dance"
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

ll dp[1003][1003], n, k, h[1003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	sort(h + 1, h + n + 1);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++) dp[i][j] = LINF;
	dp[0][0] = dp[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			dp[i][j] = min(dp[i][j], dp[i - 2][j - 1] + (h[i] - h[i - 1]));
		}
	}
	cout << dp[n][k];
}
