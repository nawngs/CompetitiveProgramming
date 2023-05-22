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

const string NAME = "UGPALIND";
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

string s[1003];

namespace solve1 {
	void solve() {
		int num = (k + 1) / 2;
		ll total = 1, sub = 1;
		for (int i = 1; i <= num; i++) {
			total = (total * 26) % MOD;
			sub = (sub * (26 - n)) % MOD;
		}
		cout << (total - sub + MOD) % MOD;
	}
}

namespace solve2 {
	ll dp[1003][1003][2][2];
	void solve() {
		for (int len = 1; len <= k; len++) {
			for (int i = 1; i <= k - len + 1; i++) {
				int j = i + len - 1;
				if (i == j) {
					dp[i][j][1][0] = dp[i][j][1][1] = 0;
					dp[i][j][0][0] = 25 - (s[1][0] != s[1][1]);
					dp[i][j][0][1] = 1 + (s[1][0] != s[1][1]);
					continue;
				}
				if (len == 2) {
					dp[i][j][1][1] = (s[1][0] == s[1][1]);
					dp[i][j][1][0] = 0;
					dp[i][j][0][0] = 25 - (s[1][0] != s[1][1]);
					dp[i][j][0][1] = 2 * (s[1][0] != s[1][1]);
					continue;
				}
				dp[i][j][1][0] = ((dp[i + 1][j - 1][1][0] + dp[i + 1][j - 1][1][1]) * (25 - (s[1][0] != s[1][1]))) % MOD;
				dp[i][j][1][1] = ((dp[i + 1][j - 1][1][0] + dp[i + 1][j - 1][1][1]) * (1 + (s[1][0] != s[1][1])) + dp[i + 1][j - 1][0][1]) % MOD;
				dp[i][j][0][0] = ((dp[i + 1][j - 1][0][1] + dp[i][j][0][0]) * (25 - (s[1][0] != s[1][1]))) % MOD;
				dp[i][j][0][1] = (dp[i + 1][j - 1][0][0] * (s[1][0] != s[1][1]) + dp[i + 1][j - 1][0][0] * (s[1][0] != s[1][1])) % MOD;
			}
		}
		cout << (dp[1][k][1][0] + dp[1][k][1][1]) % MOD << '\n';
	}
}

int main() {
	fast;
	fre();
	cin >> n >> k;
	bool sub1 = 1;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		
		sub1 &= (s[i].size() == 1);
	}
	if (sub1) solve1::solve();
	else solve2::solve();
}
