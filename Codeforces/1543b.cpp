#include <bits/stdc++.h>

using namespace std;

long long ntest, n, a[200005];

int main(){
	cin >> ntest;
	while(ntest --){
		cin >> n;
		long long sum = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			sum += a[i];
		}
		sum %= n;
		cout << (n - sum) * sum << '\n';
	}
}