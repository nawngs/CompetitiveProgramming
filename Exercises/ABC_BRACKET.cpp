//link: https://drive.google.com/file/d/1-lS98HVB6nRsyPuNcD713yHFdPPLlpKV/view
#include <bits/stdc++.h>

using namespace std;

int ntest;

int main(){
	cin >> ntest;
	while(ntest --){
		string s;
		cin >> s;
		int a, b, c, n = s.size();
		a = b = c = 0;
		for(int i = 0; i < n; i++){
			a += (s[i] == 'A');
			b += (s[i] == 'B');
			c += (s[i] == 'C');
		}
		if(a + b == c){
			int cc;
			string ans = "";
			int cnt = 0;
			if(s[0] == 'A' || s[0] == 'B') cc = -1;
			else cc = 1;
			for(int i = 0; i < n; i++){
				if(s[i] == 'C') cnt += cc;
				else cnt += (cc == 1 ? -1 : 1);
				if(cnt < 0){
					cout << "NO" << '\n';
					ans = "WR";
					break;
				}
				if(s[i] == 'C') ans = ans + (cc == 1 ? '(' : ')');
				else ans = ans + (cc == 1 ? ')' : '(');
			}
			if(ans != "WR"){
				cout << "YES\n" << ans << "\n";
			}
			continue;
		}
		if(a + c == b){
			int cc;
			string ans = "";
			int cnt = 0;
			if(s[0] == 'A' || s[0] == 'C') cc = -1;
			else cc = 1;
			for(int i = 0; i < n; i++){
				if(s[i] == 'B') cnt += cc;
				else cnt += (cc == 1 ? -1 : 1);
				if(cnt < 0){
					cout << "NO" << '\n';
					ans = "WR";
					break;
				}
				if(s[i] == 'B') ans = ans + (cc == 1 ? '(' : ')');
				else ans = ans + (cc == 1 ? ')' : '(');
			}
			if(ans != "WR"){
				cout << "YES\n" << ans << "\n";
			}
			continue;
		}
		if(b + c == a){
			int cc;
			string ans = "";
			int cnt = 0;
			if(s[0] == 'B' || s[0] == 'C') cc = -1;
			else cc = 1;
			for(int i = 0; i < n; i++){
				if(s[i] == 'A') cnt += cc;
				else cnt += (cc == 1 ? -1 : 1);
				if(cnt < 0){
					cout << "NO" << '\n';
					ans = "WR";
					break;
				}
				if(s[i] == 'A') ans = ans + (cc == 1 ? '(' : ')');
				else ans = ans + (cc == 1 ? ')' : '(');
			}
			if(ans != "WR"){
				cout << "YES\n" << ans << "\n";
			}
			continue;
		}
		cout << "NO" << '\n';
	}
}