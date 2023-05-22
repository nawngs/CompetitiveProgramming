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

const string NAME = "matrixb";
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

int n, m, a[503][503], s[503][503], dp[503][503];

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) a[i][j] = -1;
			s[i][j] = s[i][j - 1] + a[i][j];
		}
	int res = -INF;
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j++) {
			dp[i][j] = s[1][j] - s[1][i - 1];
			if (i != j) res = max(res, dp[i][j]);
		}
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			for (int k = j; k <= m; k++) {
				res = max(res, dp[j][k] + s[i][k] - s[i][j - 1]);
				if (j != k) res = max(res, s[i][k] - s[i][j - 1]);
				dp[j][k] = max(dp[j][k] + a[i][j] + a[i][k] * (j != k), s[i][k] - s[i][j - 1]);
			}
	cout << res;
}
