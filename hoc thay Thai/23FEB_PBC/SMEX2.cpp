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

ll n, a[5003], mex[5003][5003], cnt[5003], dp[5003][5003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > n) a[i] = n + 2909;
	}
	for (int i = 1; i <= n; i++) {
		memset(cnt, 0, sizeof(cnt));
		int cur = 0;
		for (int j = i; j <= n; j++) {
			if (a[j] <= n) cnt[a[j]] ++;
			while (cnt[cur] > 0) cur ++;
			mex[i][j] = cur;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		ll total = 0, r = i + 1;
		for (int j = 0; j <= n; j++) {
			while (r <= n && mex[i + 1][r] < j) {
				dp[r][mex[i + 1][r]] = (dp[r][mex[i + 1][r]] + total) % MOD;
				r ++;
			}
			total = (total + dp[i][j]) % MOD;
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) res = (res + dp[n][i]) % MOD;
	cout << res;
}