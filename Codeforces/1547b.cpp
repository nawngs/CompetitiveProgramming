//link: https://codeforces.com/problemset/problem/1547/B
#include <bits/stdc++.h>

using namespace std;


int n;
string s;

bool solve(){
	int dau = 0, cuoi = s.size() - 1;
	char ch = 'a' + cuoi;
	while(ch >= 'a'){
		if(s[dau] == ch){
			dau ++;
			ch --;
		}
		else{
			if(s[cuoi] == ch){
				cuoi --;
				ch --;
			}
			else return false;
		}
	}
	return true;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s;
		if(solve()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
