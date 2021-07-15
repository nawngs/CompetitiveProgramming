#include <bits/stdc++.h>

using namespace std;

const int MOD = 1E9 + 7;
int ntest;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> ntest;
	while(ntest --){
		long long n;
		cin >> n;
		long long ans = 0;
		ans += (n - n / 2) * 2;
		ans %= MOD;
		//long long cnt = n - n / 2;
		//cout << ans;
		long long temp = 2;
		for(int i = 3; i <= 50; i++){
			long long new_temp = (temp * i) / __gcd(temp, (long long) i);
			long long tmp = ((n / temp) - (n / new_temp));
			ans += (i * tmp) % MOD;
			ans %= MOD;
			temp = (temp * i) / __gcd(temp, (long long) i);
		}
		cout << ans % MOD << '\n';
	}
}