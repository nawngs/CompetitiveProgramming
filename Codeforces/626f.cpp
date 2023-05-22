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
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, nk, a[503], dp[203][203][1003];

// dp[i][j][k]: so cach dat den i dang co j group chua dong va gia tri hien tai la k

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> nk;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= nk; k++) {
				int newk = k + (a[i + 1] - a[i]) * j;
				if (newk > nk) continue;
				dp[i + 1][j][newk] = (dp[i + 1][j][newk] + (1ll * dp[i][j][k] * 1ll * (j + 1) % MOD)) % MOD;
				dp[i + 1][j + 1][newk] = (dp[i + 1][j + 1][newk] + dp[i][j][k]) % MOD;
				if (j > 0) 
					dp[i + 1][j - 1][newk] = (dp[i + 1][j - 1][newk] + (1ll * dp[i][j][k] * 1ll * j % MOD)) % MOD; 
			}
	ll res = 0;
	for (int k = 0; k <= nk; k++)
		res = (res + dp[n][0][k]) % MOD;
	cout << res; 
}