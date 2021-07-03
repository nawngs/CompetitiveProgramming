	#include <bits/stdc++.h>

	using namespace std;

	int ntest, n;

	int main(){
		cin >> ntest;
		while(ntest --){
			cin >> n;
			int le = 0, chan = 0;
			for(int i = 1; i <= 2 * n; i++){
				int x;
				cin >> x;
				if(x % 2 == 0) chan ++;
				else le ++;
			}
			if(chan == le) cout << "Yes" << '\n';
			else cout << "No" << '\n';
		}
	}