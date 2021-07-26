//link: https://oj.vnoi.info/problem/fc126_letters
#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int calc(string str){
	//cout << str << '\n';
	if(str == "ba") return -1;
	if(str == "ab") return 1;
	return 0;
}

int create(int pos, char ch){
	string temp1 = "";
	temp1 = temp1 + s[pos - 1] + ch;
	if(pos == n - 1 || s[pos + 1] == '?') return calc(temp1);
	string temp2 = "";
	temp2 = temp2 + ch + s[pos + 1];
	//cout << temp1 << " " << temp2 << '\n';
	return calc(temp1) + calc(temp2);
}

int main(){
	cin >> n >> s;
	if(s[0] == '?') s[0] = 'a';
	//s = s + 'c';
	int ans = 0;
	for(int i = 1; i < n; i++){
		if(s[i] == '?'){
			if(create(i, 'a') > create(i, 'b')) s[i] = 'a';
			else s[i] = 'b';
		}
		//cout << ans << '\n';
	}
	for(int i = 1; i < n; i++){
		string temp = "";
		temp = temp + s[i - 1] + s[i];
		ans += calc(temp);

	}
	cout << ans;
}