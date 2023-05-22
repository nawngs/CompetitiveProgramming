#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
	while(cin >> s){
		if(s == "[CASE]"){
			int x;
			cin >> x;
			if(x % 5 == 0 || x % 5 == 2) cout << "Hanako" << '\n';
			else cout << "Taro" << '\n';
		}
		else return 0;
	}
}