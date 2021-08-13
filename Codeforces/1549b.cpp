#include <bits/stdc++.h>

using namespace std;

int ntest;

int main(){
	cin >> ntest;
	while(ntest --){
		int n, ans = 0;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		s1 = ' ' + s1;
		s2 = ' ' + s2;
		for(int i = 1; i <= n; i++){
			if(s2[i] == '0') continue;
			if(s1[i] == '0'){
				ans ++;
				s1[i] = '2';
				continue;
			}
			if(s1[i - 1] == '1'){
				s1[i - 1] = '2';
				ans ++;
				continue;
			}
			if(s1[i + 1] == '1'){
				s1[i + 1] = 2;
				ans ++;
				continue;
			}
		}
		cout << ans << '\n';
	}
}