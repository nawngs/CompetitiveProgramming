#include <bits/stdc++.h>

using namespace std;

long long q, dp[3][5][15], sum[1000005], n, res[1000005];
string s;

long long sol1(){
	dp[0][0][0] = 1;
	sum[1] = (s[1] - '0') % 11;
	long long ans = 0, tmp = 0;
	for(int i = 2; i <= n; i++) sum[i] = (sum[i - 2] + s[i] - '0') % 11;
	for(int i = 1; i <= n; i++){
		tmp += s[i] - '0';
		tmp %= 3;
		//cout << i << " " << tmp << '\n';
		ans += dp[i % 2][tmp][(sum[i] - sum[i - 1] + 11) % 11] + dp[(i - 1) % 2][tmp][(11 - (sum[i] - sum[i - 1] + 11) % 11) % 11];
		//cout << i  << " " << tmp << " " <<  ((sum[i] - sum[i - 1] + 11) % 11) % 11 << '\n';
		//ans += calc(tmp, sum[i - 1], sum[i]);
		dp[i % 2][tmp][(sum[i] - sum[i - 1] + 11) % 11] ++;
		//dp[(i + 1) % 2][tmp][11 - (sum[i] - sum[i - 1] + 11) % 11] ++;
	
		//cout << i << " " << ans << '\n';
	}
	return ans;
}

string sol2(){
	//cout << "YES" << '\n';
	for(int k = 0; k <= 1; k++)
		for(int i = 0; i <= 4; i++)
			for(int j = 0; j <= 12; j++) dp[k][i][j] = 1e18;
	dp[0][0][0] = 0;
	string ans = "";
	sum[1] = (s[1] - '0') % 11;
	long long tmp = 0;
	long long cnt = 0, len = 0;
	for(int i = 2; i <= n; i++){
		sum[i] = (sum[i - 2] + s[i] - '0') % 11;
	}
	//cout << ans << '\n';
	for(int i = 1; i <= n; i++){
		//cout << s[i] << '\n';
		tmp += s[i] - '0';
		tmp %= 3;
		long long l = min(dp[i % 2][tmp][(sum[i] - sum[i - 1] + 11) % 11], dp[(i - 1) % 2][tmp][(11 - (sum[i] - sum[i - 1] + 11) % 11) % 11]);
		if(l != 1e18){
			//cout << l << '\n';
			long long temp = i - l;
			if(temp > len){
				len = temp;
				cnt = 1;
				res[1] = i;
			}
			else if(temp == len) res[++ cnt] = i;
		}
		//cout << i << " " << l <<'\n';
		dp[i % 2][tmp][(sum[i] - sum[i - 1] + 11) % 11] = min(dp[i % 2][tmp][(sum[i] - sum[i - 1] + 11) % 11], (long long)i);
	}
	//cout << cnt << " " << len << '\n';
	for(int i = 1; i <= cnt; i++) ans = max(ans, s.substr(res[i] - len + 1, len));
	if(ans != "") return ans;
return "-1";
}


int main(){
	//cout << max(9999, 99231) << '\n';
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> s >> q;
	n = s.size();
	s = ' ' + s;
	//cout << "YES" << '\n';
	if(q == 1) cout << sol1();
	else cout << sol2();
}