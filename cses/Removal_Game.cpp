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

ll n, a[5005], dp[5005][5005], s[5005];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			int j = i + k - 1;
			dp[i][j] = (s[j] - s[i - 1]) - min(dp[i + 1][j], dp[i][j - 1]);
			//cout << i << " " << j << " " << dp[i][j] << '\n';
		}
	}
	cout << dp[1][n];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
