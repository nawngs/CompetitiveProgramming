#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7; 
ll n, s[100005], x, y, f[100005], sumf[100005];

ll bs1 (ll val, ll r){
	ll l = 0, mid, ans = -1;
	while(l <= r){
		mid = (l + r) / 2;
		if(val - s[mid] >= x){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

ll bs2(ll val, ll r){
	ll l = 0, mid, ans = -1;
	while(l <= r){
		mid = (l + r) / 2;
		if(val - s[mid] <= y){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> x >> y;
	//n = 1e5, x = 1, y = 1e12;
	s[0] = 0;
	for(int i = 1; i <= n; i++){
		//ll a;
		cin >> a;
		a = i;
		s[i] = s[i - 1] + a;
	}
	f[0] = 1;
	sumf[0] = 1;
	for(int i = 1; i <= n; i++){
		ll rtemp = bs1(s[i], i - 1);
		ll ltemp = bs2(s[i], i - 1);
		//cout << i << " " << ltemp << " " << rtemp << '\n';
		if(ltemp == -1 || rtemp == -1 || ltemp > rtemp) continue;
		//for(int j = ltemp; j <= rtemp; j++) f[i] = (f[i] + f[j]) % MOD;
		if(ltemp == 0) f[i] = (f[i] + sumf[rtemp]) % MOD;
		else f[i] = (f[i] + sumf[rtemp] - sumf[ltemp - 1] + MOD) % MOD;

		//f[i] %= MOD;
		sumf[i] = sumf[i - 1] + f[i];
		sumf[i] %= MOD;
	}
	//for(int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i];
	cout << f[n];
}

/*
5 3 12
3 5 1 2 6

8
*/