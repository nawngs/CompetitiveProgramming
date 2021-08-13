#include <bits/stdc++.h>

using namespace std;

const int NTEST = ;

string s[15], str[15];

int main(){
	for(int i = 1; i <= NTEST; i++) cin >> s[i];
	for(int i = 1; i <= NTEST; i++) cin >> str[i];
	for(int i = 1; i <= NTEST; i++){
		if(s[i] != str[i]){
			cout << "NGU NHU CHO" << '\n';
			return 0;
		}
	}
	cout << "VAN NGU" << '\n'; 
}