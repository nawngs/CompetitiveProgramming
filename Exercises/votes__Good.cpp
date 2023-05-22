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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k;

double dp[503][503][503];

pair < int, int > a[503];


int main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].se >> a[i].fi;
		if (a[i].fi == -1) a[i].fi = INF;
	}
	sort(a + 1, a + n + 1);
	double res = INF;
	for (int tnv = 0; tnv <= k; tnv++) {
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				for (int p = 0; p <= n; p++) dp[i][j][p] = INF;
		dp[0][0][0] = 0;
		for (int i = 1; i <= n; i++) 
			for (int j = 0; j <= i; j++)
				for (int p = 0; p <= min(tnv, j); p++) {
					dp[i][j][p] = dp[i - 1][j][p];
					if (j > 0) {
						dp[i][j][p] = min(dp[i][j][p], dp[i - 1][j - 1][p] + 1.0 * a[i].se / (tnv + 1));
						if (p > 0) dp[i][j][p] = min(dp[i][j][p], dp[i - 1][j - 1][p - 1] + 1.0 * a[i].fi / p);
					}
					//cout << tnv << " " << i << " " << j << " " << p << " " << dp[i][j][p] << '\n';
					//if (j == k && p == tnv && dp[i][j][p] == 12.250000000000000) cout << p << '\n';
					if (j == k && p == tnv) res = min(res, dp[i][j][p]);
				}
	}
	cout << fixed << setprecision(15) << res << '\n';

}
