#include <bits/stdc++.h>

using namespace std;

int ntest;

int main(){
	cin >> ntest;
	while(ntest --){
		int n;
		cin >> n;
		if(n % 2 == 0){
			for(int i = 1; i <= n; i += 2) cout << i + 1 << " " << i << " ";
		}
		else{
			cout << "3 1 2 ";
			for(int i = 4; i <= n; i += 2) cout << i + 1 << " " << i << " ";
		}
		cout << '\n';
	}
}