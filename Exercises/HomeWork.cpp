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

const string NAME = "HomeWork";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[200006], dp[200006][2];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= 1; j++) dp[i][j] = INF;
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i][0], dp[i - 1][1] + (a[i] == 1));
		dp[i][1] = min(dp[i][1], dp[i - 1][0]);
		if (i >= 2) {
			dp[i][0] = min(dp[i][0], dp[i - 2][1] + (a[i - 1] == 1) + (a[i] == 1));
			dp[i][1] = min(dp[i][1], dp[i - 2][0]);
		}

	}
	cout << min(dp[n][1], dp[n][0]) << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
