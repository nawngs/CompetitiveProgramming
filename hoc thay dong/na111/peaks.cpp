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
const ll MOD = 239;
const ll BASE = 2309;

int n, k, dp[1000003][32];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++) {
			dp[i + 1][j + 1] += (i + 1 - 2 * j) * dp[i][j];
			dp[i + 1][j] += 2 * j * dp[i][j];
			dp[i + 1][j + 1] %= MOD; dp[i + 1][j] %= MOD;
		}
	cout << dp[n][k];
}


