#include <bits/stdc++.h>

using namespace std;

int n, q, a[10003], f[10003][10003], l, k, ans[10003][10003];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("Similar.Inp", "r", stdin);
	freopen("Similar.Out", "w", stdout);
	cin >> n >> l;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = n; i >= 1; i --){
		for(int j = n; j > i; j--){
			f[i][j] = f[i + 1][j + 1] + (a[i] != a[j]) - (i + l <= n && j + l <= n && a[i + l] != a[j + l]);
			f[j][i] = f[i][j];
		}
	}
	for(int i = 1; i <= n - l + 1; i++){
		for(int j = 1; j <= n - l + 1; j++){
			if(i != j) ans[i][f[i][j]] ++;
		}
		for(int j = 1; j <= l ; j++){
			ans[i][j] += ans[i][j - 1];
		}
	}
	cin >> q;
	while(q --){
		cin >> k;
		for(int i = 1; i <= n - l + 1; i++){
			cout << ans[i][k] << ' ';
		}
		cout << "\n";
	}
}