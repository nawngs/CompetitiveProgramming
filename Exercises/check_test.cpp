#include <bits/stdc++.h>

using namespace std;

const int NTEST = 100000;

string s[NTEST + 5], str[NTEST + 5];

int main(){
	freopen("check_test.inp", "r", stdin);
	for(int i = 1; i <= NTEST; i++) cin >> s[i];
	for(int i = 1; i <= NTEST; i++) cin >> str[i];
	for(int i = 1; i <= NTEST; i++){
		if(s[i] != str[i]){
			cout << "sai o " << i << '\n';
			//cout << "NGU NHU CHO" << '\n';
			return 0;
		}
	}
	cout << "VAN NGU" << '\n'; 
}