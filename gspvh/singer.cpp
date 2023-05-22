#include <bits/stdc++.h>

#define name "singer"
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
const ll MOD = 998244353;
const ll BASE = 2309;

ll dp[6425][6425], n, d, t, s1[6425][6425], s2[6425][6425];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> d >> t;
	d --;
	dp[0][0] = 2;	
	s1[0][0] = s2[0][0] = 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			dp[i][j] = s1[i - 1][j];
			if (i >= d && j > 0) dp[i][j] = (dp[i][j] - s1[i - d][j] + s2[i - d][j - 1]) % MOD;
			s1[i][j] = (s1[i - 1][j] + dp[i][j]) % MOD;
			s2[i][j] =  dp[i][j];
			if (j > 0) s2[i][j] = (s2[i][j] + s2[i - 1][j - 1]) % MOD;
			// for (int l = 1; l <= i; l++) {
			// 	if (j < max(l - d + 1, 0ll)) break;
			// 	dp[i][j] += dp[i - l][j - max(l - d + 1, 0ll)];
			// }
		}
	}
	cout << (dp[n][t]) % MOD;
}
