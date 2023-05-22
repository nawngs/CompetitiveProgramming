//link: https://oj.vnoi.info/problem/c11prime
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const  ll nmax = 1e6;

ll cnt[nmax + 5];
bool check[nmax + 5];
vector < ll > prime;

void sang(){
	for(int i = 1; i <= nmax; i++) check[i] = true;
	check[1] = check[0] = false;	
	for(int i = 2; i * i <= nmax; i++){
		if(check[i])
			for(int j = i * i; j <= nmax; j += i) check[j] = false;
	}
	for(int i = 1; i <= nmax; i++){
		if(check[i]) prime.push_back(i);
	}
}

int main(){
	ll x;
	cin >> x;
	sang();
	//cout << prime.size() << '\n';
	ll tempx = x;
	for(int i = 0; i < prime.size(); i++){
		if(tempx == 1) break;
		while(tempx % prime[i] == 0){
			cnt[prime[i]] ++;
			tempx /= prime[i];
		}
	}
	if(tempx != 1){
		if(x > 1e12){
			if((ll) sqrtl(x) * (ll) sqrtl(x) == x) cout << (ll) sqrtl(x) << " " << 2;
			else cout << 0;
		}
		else cout << 0;
		return 0;
	}
	ll temp = -1;
	ll ans = -1;
	for(int i = 2; i <= nmax; i++){
		if(cnt[i] > 1){
			if(ans == -1 && temp == -1){
				ans = i;
				temp = cnt[i];
			}
			else{
				cout << 0;
				return 0;
			}
		}
	}
	if(ans == -1 && temp == -1) cout << 0 << '\n';
	else cout << ans <<  " " << temp; 
}