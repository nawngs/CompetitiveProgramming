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
const ll LINF = 1E15;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, s[303], dp[303][303][303][2];

// 0 la minh
// 1 la doi thu

string str;

int main() {
	fast;
	cin >> n >> k >> str;
	str = ' ' + str;
	for (int i = 1; i <= n; i++) 
		s[i] = s[i - 1] + (str[i] == 'B');

	for (int len = 1; len <= n; len++) {
		for (int i = 1; i <= n - len + 1; i++) {
			int j = (i + len - 1);
			dp[i][j][0][0] = dp[i][j][0][1] = 0;
			for (int k = 1; k <= s[n]; k++) {
				dp[i][j][k][0] = dp[i][j][k][1] = -LINF;
				if (k > s[j] - s[i - 1]) break;
				if (i == j) {
					dp[i][j][k][0] = 1;
					continue;
				}
				dp[i][j][k][0] = max(dp[i + 1][j][(k - (str[i] == 'B'))][1], dp[i][j - 1][k - (str[i] == 'B')][1]);
				dp[i][j][k][0] = min(dp[i + 1][j][k][1], dp[i][k - 1][k][1]);	
			}
		}
	}
}
