#include <bits/stdc++.h>

using namespace std;

int ntest;

int main(){
	cin >> ntest;
	while(ntest --){
		int s;
		cin >> s;
		int ans = 1;
		int sum = 1;
		int i = 1;
		while(sum < s){
			i += 2;
			sum += i;
			ans ++;
		}
		cout << ans << '\n';
	}
}