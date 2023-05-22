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

const string NAME = "TKSEQ";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, a[503], dp[503][503];

int main() {
	fast;
	fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++) 
		for (int j = 1; j <= 3 * k; j++) dp[i][j] = -INF;
	dp[1][1] = a[1];
	ll res = -INF;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= 3 * k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (dp[i - 1][j - 1] != -INF) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i] * (j % 3 == 2 ? -1 : 1));
		}
		res = max(res, dp[i][3 * k]);
	}	

	cout << res;
}
