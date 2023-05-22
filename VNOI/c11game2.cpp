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
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[203], b[203], dema, demb, dp[203][203][203];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x != 0) a[++ dema] = x;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x != 0) b[++demb] = x;
	}
	for (int i = 0; i <= dema; i++) {
		for (int j = 0; j <= demb; j++) {
			for (int cnt1 = 0; cnt1 <= n - dema; cnt1 ++) {
				dp[i][j][cnt1] = -INF;
				if (i + cnt1 - j > n - demb || cnt1 + i < j) continue;
				if (i == j && j == 0) {
					dp[i][j][cnt1] = 0;
					continue;
				}
				if (i > 0) dp[i][j][cnt1] = max(dp[i][j][cnt1], dp[i - 1][j][cnt1]);
				if (j > 0 && cnt1 > 0) dp[i][j][cnt1] = max(dp[i][j][cnt1], max(dp[i][j][cnt1 - 1], dp[i][j - 1][cnt1 - 1]));
				if (i > 0 && j > 0) dp[i][j][cnt1] = max(dp[i][j][cnt1], dp[i - 1][j - 1][cnt1] + a[i] * b[j]);

			}
		}
	}
	cout << dp[dema][demb][n - dema];
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
