#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll ntest, a[5][5];

void cnt_bef( ll &ans){
		if(a[1][3] - a[1][2] == a[1][2] - a[1][1]) ans ++;
		if(a[3][3] - a[3][2] == a[3][2] - a[3][1]) ans ++;
		if(a[3][1] - a[2][1] == a[2][1] - a[1][1]) ans ++;
		if(a[3][3] - a[2][3] == a[2][3] - a[1][3]) ans ++;
}

ll check(ll x){
	ll dem = 0;
	if((a[1][1] + a[3][3]) % 2 == 0 && a[1][1] + a[3][3] == 2 * x) dem ++;
	if((a[1][3] + a[3][1]) % 2 == 0 && a[1][3] + a[3][1] == 2 * x) dem ++;
	if((a[2][1] + a[2][3]) % 2 == 0 && a[2][1] + a[2][3] == 2 * x) dem ++;
	if((a[1][2] + a[3][2]) % 2 == 0 && a[1][2] + a[3][2] == 2 * x) dem ++;
	return dem;
}

int main(){
	cin >> ntest;
	for(int i = 1; i <= ntest; i++){
		ll  ans = 0;
		memset(a, 255, sizeof(a));
		for(int i = 1; i <= 3; i++) cin >> a[1][i];
		cin >> a[2][1] >> a[2][3];
		a[2][2] = -1e18;
		for(int i = 1; i <= 3; i++) cin >> a[3][i];
		cnt_bef( ans);
		//cout << check((a[1][1] + a[3][3]) / 2) << '\n';
		cout <<"Case #" << i << ": " <<  ans + max(check((a[1][1] + a[3][3]) / 2),
					 max(check((a[2][1] + a[2][3]) / 2), 
					 max(check((a[1][3] + a[3][1]) / 2), 
					 	check((a[1][2] + a[3][2]) / 2)))) << '\n';
	}
}