#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "brothers";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[203][203], s[203][203], maxa[203][203][203], dp[203][203][203];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			s[i][j] = s[i][j - 1] + a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= m; k++) dp[i][j][k] = -INF;
	dp[1][1][1] = a[1][1];
	for (int i = 2; i <= m; i++) dp[1][1][i] = dp[1][1][i - 1] + a[1][i];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = j + 1; k <= m; k++) {
				int posl, posr;
				for (int p = 1; p <= j; p++) {
					for (int q = k; q > j; q--) {
						if (dp[i - 1][p][q] + s[i][j] - s[i][p - 1] + s[i][k] - s[i][q - 1] > dp[i][j][k]) {
							dp[i][j][k] = max(dp[i][j][k], dp[i - 1][p][q] + s[i][j] - s[i][p - 1] + s[i][k] - s[i][q - 1]);
							posl = p;
							posr = q;
						}
					}
					
				}
				cout << i << " " << j << " " << k << " " << dp[i][j][k] << " " << posl << " " << posr << '\n';
			}
		}
	}
	cout << dp[n][m - 1][m];

}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
