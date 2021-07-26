#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll ntest;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("SplitKO.Inp", "r", stdin);
	//freopen("SplitKO.Out", "w", stdout);
	cin >> ntest;
	while(ntest --){
		ll n, k, a[10005], dem = 0;
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(abs(a[i]) % 2 == 1) dem ++;
		}
		//cout << dem << '\n';
		if(dem < k){
			cout << "No" << '\n';
			continue;
		}
		if(dem % 2 == k % 2) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}