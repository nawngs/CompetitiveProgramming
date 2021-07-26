#include <bits/stdc++.h>

using namespace std;

string s;
int m, n, sum[1000005];

int sol(int x){
	long long cnt = 0;
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i < n; i++){
		sum[i] = sum[i] + sum[i - 1];
		char temp = s[i] + (sum[i] % 2);
		//cout << x << " " << sum[i] << '\n';
		if(temp == '2') temp = '0';														
	//	cout << x << " " << i << " " << sum[i] << " " << s[i] <<  '\n';
		if(temp != x + '0'){
			if(i + m - 1 < n){
				//cout << x << " " << i << '\n';
				cnt ++;
				sum[i] ++;
				sum[i + m] --;
				//s[i] = x + '0';
			}
			else return 1e9;
		}
		//sum[i] %= 2;
		//cout << x << " " << i << " " << sum[i] << '\n';
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("BITSTR.INP", "r", stdin);
	freopen("BITSTR.OUT", "w", stdout);
	cin >> s >> m;
	n = s.size();
	int ans = min(sol(1), sol(0));
	if(ans == 1e9) cout << -1 << '\n';
	else cout << ans << '\n';
}