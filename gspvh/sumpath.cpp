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

const string NAME = "sumpath";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, dp[2209][2209], cnt[2209][2209];

char s[2209][2209];

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> s[i][j];
	dp[1][1] = s[1][1] - '0';
	cnt[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j && i == 1) continue;
			if (i > 1) {
				dp[i][j] += dp[i - 1][j] + ((s[i][j] - '0') * cnt[i - 1][j]) % MOD;
				cnt[i][j] += cnt[i - 1][j];
			}
			if (j > 1) {
				dp[i][j] += dp[i][j - 1] + (cnt[i][j - 1] * (s[i][j] - '0')) % MOD;
				cnt[i][j] += cnt[i][j - 1];
			}
			if (i > 1 && j > 1) {
				dp[i][j] += dp[i - 1][j - 1] + (cnt[i - 1][j - 1] * (s[i][j] - '0')) % MOD;
				cnt[i][j] += cnt[i - 1][j - 1];
			}
			dp[i][j] %= MOD;
			cnt[i][j] %= MOD;
			//cout << i << " " << j << " " << dp[i][j] << '\n';
		}
	}
	cout << dp[n][m];
}
