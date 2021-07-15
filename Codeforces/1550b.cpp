#include <bits/stdc++.h>

using namespace std;

int ntest;

int main(){
	cin >> ntest;
	while(ntest --){
		int n, a, b;
		string s;
		cin >> n >> a >> b >> s;
		if(b >= 0){
			cout << a * n + b * n << '\n';
			continue;
		}
		char ch = s[0];
		int cnt1 = 0;
		int cnt0 = 0;
		s[n + 1] = '2';
		for(int i = 1; i <= n; i++){
			if(s[i] != ch){
				//cout << ch << '\n';
				if(ch == '1') cnt1 ++;
				else cnt0 ++;
				ch = s[i];
			}
		}
		if(cnt1 < cnt0) ch = '1';
		else ch = '0';
		//cout << cnt1 << " " << cnt0 << '\n';
		int temp = n;
		int tam = 0;
		long long ans = 0;
		for(int i = 0; i <= n; i++){
			if(s[i] == ch) tam ++;
			else{
				temp -= tam;
				//cout << tam << '\n';
				if(tam != 0) ans += a * tam + b;
				//cout << ans << '\n';
				tam = 0;
			}
		}
		//cout << temp << '\n';
		cout << ans + a * temp + b << '\n';
	}
}