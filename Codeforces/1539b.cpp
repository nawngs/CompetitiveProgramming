#include <bits/stdc++.h>

using namespace std;

long long dp[100005], n, q;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q >> s;
	for(int i = 0; i < n; i++){
		dp[i + 1] = dp[i] + (s[i] - 'a' + 1);
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << dp[r] - dp[l - 1] << '\n';
	}
}