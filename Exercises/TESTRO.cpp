#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
int n, m, dp[100005][1005], ans = 0;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("TESTRO.INP", "r", stdin);
	freopen("TESTRO.OUT", "w", stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	for(int i = 1; i <= m; i++){
		if(s[i] == 'R'){
			for(int j = 3; j <= n; j++){
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				dp[i][j] %= MOD;
			}
			dp[i][2] = (dp[i - 1][2] + dp[i - 1][1] + 1) % MOD;
			dp[i][1] = dp[i - 1][1];
		}
		else{
			for(int j = 1; j <= n - 1; j++){
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
				dp[i][j] %= MOD;
			}
			dp[i][n] = dp[i - 1][n];
		}
	}
	cout << dp[m][1] % MOD;
}
