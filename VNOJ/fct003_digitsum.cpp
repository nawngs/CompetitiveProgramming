//link: https://oj.vnoi.info/problem/fct003_digitsum
#include <bits/stdc++.h>

using namespace std;

long long a, b;

long long int unsigned sum(long long x){
	long long int unsigned ans = 0;
	long long pre = 0;
	long long mu_10 = 1;
	while(x > 0){
		long long tmp = x % 10;
		long long new_x = x / 10;
		//if(new_x == 0) new_x = 1;
		new_x ++;
		//if(x == 102) cout << new_x << '\n';
		for(int i = 1; i <= 9; i++){
			if(i < tmp) ans += i * new_x * mu_10;
			if(i >= tmp){
				ans += i * (new_x - 1) * mu_10;
			}
		}
		ans += tmp * (pre + 1);
		pre += tmp * mu_10;
		x = x / 10;
		mu_10 *= 10;
		//cout << x << " " << ans << '\n';
	}
	//cout << ans << '\n';
	return ans;
}

int main(){
	cin >> a >> b;
	//a = 1;
	//b = 1e15;
	cout << sum(b) - sum(a - 1);
}