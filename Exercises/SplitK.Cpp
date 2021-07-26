#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll ntest;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("SplitK.Inp", "r", stdin);
	freopen("SplitK.Out", "w", stdout);
	cin >> ntest;
	while(ntest --){
		ll n, k, dem = 0, a[10005];
		cin >> n >> k;
		a[0] = -1e18;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(a[i] < a[i - 1]) dem ++;
		}
		if(dem >= k) cout << "No" << '\n';
		else cout << "Yes" << '\n';
	}
}