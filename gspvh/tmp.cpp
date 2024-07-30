#include <bits/stdc++.h>

#define name "putnik"
using namespace std;

int n, d[1503][1503], dp[1503][1503][3];

int main() {
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> d[i][j];
	memset(dp, 0x3f, sizeof dp);
	dp[2][1][0] = d[2][1];
	dp[2][1][1] = d[1][2];
	for(int i = 2; i <= n - 1; i++)
		for(int j = 1; j <= i - 1; j++)
			for(int k = 0; k <= 1; k++)
			{
				int first = (k == 0) ? i : j;
				int last = (k == 1) ? i : j;
				dp[i + 1][last][0] = min(dp[i][j][k] + d[i + 1][first], dp[i + 1][last][0]);
				dp[i + 1][first][1] = min(dp[i + 1][first][1], dp[i][j][k] + d[last][i + 1]);
			}
	int ans = 1e9;
	for(int i = 1; i < n; i++)
		for(int j = 0; j <= 1; j++)
			ans = min(ans, dp[n][i][j]);
	cout << ans;
	return 0;
}