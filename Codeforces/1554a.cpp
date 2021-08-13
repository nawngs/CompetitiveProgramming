#include <bits/stdc++.h>

using namespace std;

long long ntest, n, a[100005];

int main(){
	//cout <<  (4 ^ 1) << '\n';
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> ntest;
	while(ntest --){
		cin >> n;
		long long ans = 0;
		 a[n + 1] = a[0] = 1e9 + 7;
		for(int i = 1; i <= n; i++){
			cin >> a[i];

		}
		for(int i = 1; i <= n; i++){
			if(a[i - 1] <= a[i]) ans = max(ans, a[i] * a[i - 1]);
			if(a[i + 1] <= a[i]) ans = max(ans, a[i] * a[i + 1]);
		}
		cout << ans << '\n';
	}
}