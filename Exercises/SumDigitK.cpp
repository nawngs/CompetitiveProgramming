#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

string s;

ll dp[10005][105][3], a[10005], d;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("SumDigitK.inp", "r", stdin);
	//freopen("SumDigitK.out", "w", stdout);
	cin >> s >> d;
	ll n = s.size();
	for (int i = 0; i < s.size(); i++) a[i + 1] = s[i] - '0';
	//1 la chua be hon
	//0 la da be hon
	for (int i = 0; i < a[1]; i++) dp[1][i % d][0] ++;
	dp[1][a[1] % d][1] ++;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < d; j++) {
			for (int digit = 0; digit <= 9; digit++) {
				if (digit < a[i]) {
					dp[i][j][0] += dp[i - 1][((j - digit) % d + d) % d][0] + dp[i - 1][((j - digit) % d + d) % d][1];
					dp[i][j][0] %= MOD;
				}
				if (digit == a[i]) {
					dp[i][j][0] += dp[i - 1][((j - digit) % d + d) % d][0];
					dp[i][j][0] %= MOD;
					dp[i][j][1] += dp[i - 1][((j - digit) % d + d) % d][1];
					dp[i][j][1] %= MOD;

				}
				if (digit > a[i]) {
					dp[i][j][0] += dp[i - 1][((j - digit) % d + d) % d][0];
					dp[i][j][0] %= MOD;
				}
			}
		}
	}
	cout << (dp[n][0][0] + dp[n][0][1] - 1 + MOD) % MOD;
}
