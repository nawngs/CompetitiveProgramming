#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "T3E10";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[200005], dp[200005][5][15];

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0][0] = 1;
		for (int j = 1; j <= 3; j++) {
			for (int k = 0; k <= 10; k++) {
				dp[i][j][k] += dp[i - 1][j][k];
				if (k >= a[i]) dp[i][j][k] += dp[i - 1][j - 1][k - a[i]];
 			}
		}
	}
	cout << dp[n][3][10];
}
