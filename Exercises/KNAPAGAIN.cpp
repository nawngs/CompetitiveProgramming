#include <bits/stdc++.h>

using namespace std;

long long n, m, a[1005], w[1005], dp[1005][50005];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> w[i];
	
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i <= n; i++)
		for(int j = 1; j <= 50000; j++) dp[i][j] = 1e18;
	dp[0][0] = 0;

	for(int i = 1; i <= n; i++){
		//cout << i << " " << a[i] << " " << w[i] << '\n';
		for(int j = 1; j <= 50000; j++){
			if(j < w[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - w[i]] + a[i]);
			//cout << i << " " << j << " " << dp[i][j] << '\n';
		}
		//cout << "##################################################" << '\n';
	}

	long long ans=  0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 50000; j++) if(dp[i][j] <= m) ans = max(ans, (long long) j);
	cout << ans << '\n';
}