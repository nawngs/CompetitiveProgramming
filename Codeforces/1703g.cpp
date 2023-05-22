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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e15;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, a[100003], dp[100003][35];

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 32; j++) dp[i][j] = -INF;
	dp[0][0] = 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll tam = a[i];
		for (int j = 0; j <= min(i, 32); j++) {
			if (j > 0) tam /= 2;
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + tam - k);
			if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + tam);
			if (i == n) ans = max(ans, dp[i][j]);
			//cout << i << " " << j << " " << tam << " " << dp[i][j] << '\n';
		}
		ans = max(ans, dp[i][32]);
	}
	cout << ans << '\n';

}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}

/*
1
44 23455
4867 8882 836 24348 3480 19467 17199 21947 18398 32529 20431 23811 20429 7728 7410 2140 24253 25261 3801 15058 23581 9353 12942 19990 30823 22952 20600 10949 29779 4146 3372 13805 26700 26682 3206 14286 8224 20637 19193 8157 24315 2861 8483 18959 
*/