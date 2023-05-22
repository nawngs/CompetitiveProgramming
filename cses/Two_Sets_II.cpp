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

const string NAME = "";
const string NAME2 = "TEST";
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

ll n, dp[503][250003];

void sol() {
	cin >> n;
	dp[0][0] = 1;
	ll sum = n * (n + 1) / 2;
	if (sum % 2 == 1) {
		cout << 0;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum / 2; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= i) dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
		}
	}
	if (sum % 2 == 1) cout << 0;
	else cout << dp[n][sum / 2] ;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
