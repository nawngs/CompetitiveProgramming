#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
	cin >> n;
	while(n --){
		long long x;
		cin >> x;
		if(x % 2 == 1){
			cout << 2 << " " << x - 1 << '\n';
			continue;
		}
		else{
			cout << 2 << " " << x << '\n';
			continue;
		}
	}
}