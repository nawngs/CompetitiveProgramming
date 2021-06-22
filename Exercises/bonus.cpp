//VOI 2020
#include <bits/stdc++.h>

using namespace std;

long long n, k, a[305], dp[305][305][155], ans = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("bonus.inp", "r", stdin);
	//freopen("bonus.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int len = 1; len < n; len ++){
		for(int i = 1; i <= n; i++){
			int j = i + len;
			if(len == 1){
				dp[i][j][1] = abs(a[i] - a[j]);
			}
			else{
				for(int t = 1; t <= k; t++) {
					dp[i][j][t] = max(dp[i + 1][j - 1][t - 1] + abs(a[i] - a[j]), 
														max(dp[i][j - 2][t - 1] + abs(a[j] - a[j - 1]), 
														max(dp[i + 2][j][t - 1] + abs(a[i] - a[i + 1]), 
														max(dp[i + 1][j][t], dp[i][j - 1][t]))));
					//if(t == k) ans = max(ans, dp[i][j][t]);
				}
			}
		}
	}
	cout << dp[1][n][k];
}