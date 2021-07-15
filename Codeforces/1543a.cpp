#include <bits/stdc++.h>

using namespace std;

int ntest;

int main(){
	cin >> ntest;
	while(ntest --){
		long long a, b;
		cin >> a >> b;
		long long tam = abs(a - b);
		if(tam == 0){
			cout << 0 << " " << 0 << '\n';
			continue;
		}
		if(a % tam == 0){
			cout << tam << " " << 0 << '\n';
			continue;
		}
		long long c = tam * (a / tam);
		//cout << c << '\n';
		long long d = tam * (a / tam + 1);
		cout << tam << " " << min(a - c, d - a) << '\n';
	}
}