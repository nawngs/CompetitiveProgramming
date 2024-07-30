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
const int N = 2e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll dp[N + 3][N + 3], n, s, t;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> s >> t;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= i; j++) {
			if (i == s || i == t) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
			else dp[i][j] = (dp[i - 1][j + 1] * j + dp[i - 1][j - 1] * max(0, j - (i > s) - (i > t))) % MOD;
		}
	cout << dp[n][1];
}