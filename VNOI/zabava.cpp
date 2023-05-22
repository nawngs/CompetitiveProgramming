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

ll n, m, k, a[103], f[103][503], dp[103][503];

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x] ++;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0) {
				f[i][j] = a[i] * (a[i] + 1) / 2;
				continue;
			}
			ll tam1 = a[i] / (j + 1);
			ll tam2 = a[i] % (j + 1);
			ll tam3 = (j + 1) - tam2;
			f[i][j] = tam2 * (tam1 + 1) * (tam1 + 2) / 2 + tam3 * tam1 * (tam1 + 1) / 2;
		}
	}
	for (int i = 1; i <= m; i++) 
		for (int j = 0; j <= k; j++) {
			dp[i][j] = dp[i - 1][j] + f[i][0];
			for (int p = 0; p <= j; p++) dp[i][j] = min(dp[i][j], dp[i - 1][p] + f[i][j - p]);
		}
	cout << dp[m][k];	
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
