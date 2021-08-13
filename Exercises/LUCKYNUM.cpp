#include <bits/stdc++.h>

using namespace std;

long long n;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("LUCKYNUM.inp", "r", stdin);
	freopen("LUCKYNUM.out", "w", stdout);
	string s = "";
	cin >> n;
	int cnt, sum = 1;
	for(int i = 1; i <= 35; i++){
		if(sum + (1 << i) > n){
			cnt = i;
			n -= sum;
			break;
		} 
		sum += (1 << i);
	}
	//cout << l << " " << n << '\n';
	for(int i = cnt - 1; i >= 0; i--){
		if(n >= (1 << i)){
			n -= (1 << i);
			s = s + '7';
		}
		else s = s + '4';
	}
	cout << s << '\n';
}