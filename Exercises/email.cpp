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

const string NAME = "email";
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

int n, a[55], dp[55][55][55];

void minimize(int &x, int y) {
	if (x > y) x = y;
}

int main() {
	fast;
	fre();
	vector < int > roi_rac;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		roi_rac.push_back(a[i]);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(roi_rac.begin(), roi_rac.end(), a[i]) - roi_rac.begin() + 1;
	for (int len = 1; len <= n; len++) 
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			for (int v = 0; v <= n; v++)
				dp[i][j][v] = INF;
			if (i == j) {
				dp[i][j][0] = 1;
				dp[i][j][a[i]] = 0;
				continue;
			}
			for (int k = i; k < j; k++) {
				minimize(dp[i][j][0], dp[i][k][0] + dp[k + 1][j][0]);
				for (int v = 1; v <= n; v++) {
					minimize(dp[i][j][v], dp[i][k][v] + min(dp[k + 1][j][v], dp[k + 1][j][0]));
					minimize(dp[i][j][v], min(dp[i][k][0], dp[i][k][v]) + dp[k + 1][j][v]);
					minimize(dp[i][j][0], dp[i][j][v] + 1);
				}
			}
		}
	cout << dp[1][n][0];
}
