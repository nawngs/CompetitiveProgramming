#include <bits/stdc++.h>

using namespace std;

int n, m, a[205][205], dp[1005][205][205], s[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("SERV.Inp", "r", stdin);
	freopen("SERV.Out", "w", stdout);
	
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) cin >> a[i][j];

	for(int i = 1; i <= m; i++) cin >> s[i];

	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++) dp[i][j][k] = 1e9;

	dp[1][2][3] = a[1][s[1]];
	dp[1][1][2] = a[3][s[1]];
	dp[1][1][3] = a[2][s[1]];

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			for(int k = j + 1; k <= n; k++){
				//if(s[i] == j || s[i] == k) continue;
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + a[s[i]][s[i + 1]]);
				dp[i + 1][min(s[i], j)][max(s[i], j)] = min(dp[i + 1][min(s[i], j)][max(s[i], j)], dp[i][j][k] + a[k][s[i + 1]]);
				dp[i + 1][min(s[i], k)][max(s[i], k)] = min(dp[i + 1][min(s[i], k)][max(s[i], k)], dp[i][j][k] + a[j][s[i + 1]]);
			}
		}
	}	

	int ans = 1e9;

	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++) ans = min(ans, dp[m][i][j]);

	cout << ans;
}