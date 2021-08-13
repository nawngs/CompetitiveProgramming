#include <bits/stdc++.h>

using namespace std;

int n, a[1000005], ans = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("BALL.inp", "r", stdin);
	freopen("BALL.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	//a[1] = a[n + 1] = 1e9;
	int l = 1;
	while(l <= n){
		int r = l;
		while(a[r + 1] > a[r] && r + 1 <= n) r ++;
		ans = max(ans, a[r] - a[l]);
		//cout << a[r] - a[l] << '\n';
		l = r + 1; 
	}
	l = 1;
	while(l <= n){
		int r = l;
		while(a[r + 1] < a[r] && r + 1 <= n) r ++;
		ans = max(ans, a[l] - a[r]);
		//cout << a[l] - a[r] << '\n';
		l = r + 1;
	}
	cout << ans;
}