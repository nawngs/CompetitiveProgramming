#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;

int main(){
	cin >> n >> k >> s;
	string s_rev = s;
	reverse(s_rev.begin(), s_rev.end());
	string str = s + s_rev;
	string mins = s;
	for(int i = 1; i < n; i++){
		string tmps = "";
		for(int j = 0; j < n; j++) tmps += str[i + j];
		//cout << tmps << '\n';
		if(tmps < mins){
			mins = tmps;
		}
	}
	s = mins;
	cout << s << '\n';
	int cnt = 1;
	k --;
	for(int i = 1; i < n; i++){
		if(s[i] == s[0]) cnt ++;
		else break;
	}
	int tmp = cnt;
	while(cnt < n && k > 0){
		cnt *= 2;
		k --;
	}
	//cout << cnt << '\n';
	if(cnt >= n){
		for(int i = 1; i <= n; i++) cout << s[0];
	}
	else{
		for(int i = 0; i < cnt; i++) cout << s[0];
		for(int i = cnt; i < n; i++) cout << s[i - cnt + tmp];
	}
}