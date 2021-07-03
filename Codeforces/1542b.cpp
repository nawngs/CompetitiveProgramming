#include <bits/stdc++.h>

using namespace std;

int ntest;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> ntest;
	while(ntest --){
		int a, b, n;
		cin >> n >> a >> b;
		if(a == 1){
			if((n - 1) % b == 0) cout << "Yes" << '\n';
			else cout << "No" << '\n';
			continue;
		}
		bool ans = false;
		long long tam = 1;
		while(1){
			//cout << n << '\n';
			if(tam > n) break;
			if((n - tam) % b == 0){
				ans = true;
				break;
			}
			tam *= a;
		}
		if(ans == true) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}	