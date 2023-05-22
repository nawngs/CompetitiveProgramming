#include <bits/stdc++.h>

using namespace std;

int n;

int main(){
	cin >> n;
	if(n % 2 == 1){
		cout << 2;
		return 0;
	}
	n /= 2;
	cout << n % 2;
}