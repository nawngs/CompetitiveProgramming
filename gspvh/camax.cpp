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

const string NAME = "camax";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[500003], t, k;

ll dp[500003][3];

void sol() {
	cin >> t >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll res1 = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= k) {
			dp[i][1] = dp[i - 1][1] + 1;
			dp[i][2] = dp[i - 1][2] + dp[i - 1][2] + 1;
			dp[i][1] %= MOD;
			dp[i][2] %= MOD;
		}
		else {
			dp[i][1] = 0;
			dp[i][2] = dp[i - 1][2];
			dp[i][1] %= MOD;
			dp[i][2] %= MOD;
		}
		//cout << i << " " << dp[i][2] << '\n';
		res1 += dp[i][1];
		res1 %= MOD;
	}	
	cout << res1 << " " << dp[n][2];
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
