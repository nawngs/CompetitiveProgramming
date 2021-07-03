//link: https://oj.vnoi.info/problem/nksp
#include <bits/stdc++.h>

using namespace std;

string s;
long long dp[1005], ans = 0;
bool f[1005][1005];

int main(){
	cin >> s;
	int n = s.size();
	memset(f, false, sizeof(f));
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n - k; i++){
			if(k == 0) f[i][i + k] = true;
			if(k == 1){
				f[i][i + k] = (s[i] == s[i + k]);
			}
			if(k >= 2){
				if(s[i] == s[i + k]) f[i][i + k] = f[i + 1][i + k - 1];
				else f[i][i + k] = false;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(f[i][j]){
				dp[j] += dp[i - 1] + 1;
				if(f[i - 1][j - 1]) dp[j] -= dp[i - 1];
			}


		}

		//cout << i << " " << dp[i] << '\n';
		ans += dp[i];
	}
	cout << ans;
}