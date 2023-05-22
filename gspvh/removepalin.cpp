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

const string NAME = "removepalin";
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

string s;

int dp[1000003][5][5];

void sol() {
	cin >> s;
	int n = s.size();
	if (n == 1) {
		cout << 0 << '\n';
		return ;
	}
	int res = INF;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) dp[i][j][k] = INF;
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			int c1 = (s[1] - 'a' + i + 26) % 26;
			int c0 = (s[0] - 'a' + j + 26) % 26;
			if (c1 == c0) continue;
			dp[1][i + 2][j + 2] = abs(i) + abs(j);
			if (n == 2) res = min(res, dp[1][i + 2][j + 2]);
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = -2; j <= 2; j++) {
			int c1 = (s[i] - 'a' + j + 26) % 26;
			for (int p = -2; p <= 2; p++) {
				int c2 = (s[i - 1] - 'a' + p + 26) % 26;
				if (c1 == c2) continue;
				for (int q = -2; q <= 2; q++) {
					int c3 = (s[i - 2] - 'a' + q + 26) % 26;
					if (c3 == c2 || c3 == c1) continue;
					dp[i][j + 2][p + 2] = min(dp[i][j + 2][p + 2], dp[i - 1][p + 2][q + 2] + abs(j));
				}
				//cout << i << " " << j << " " << p << " " << dp[i][j + 2][p + 2] << '\n';
				if (i == n - 1) res = min(res, dp[i][j + 2][p + 2]);	
			}
		}
	}
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
