#include <bits/stdc++.h>

using namespace std;

const long long oo = 1e18;
long long n, a[200005], f[200005], res = -oo, pos;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("insert.inp", "r", stdin);
	freopen("insert.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		f[i] = n + 1;
	}
	a[n + 1] = oo;
	a[0] = -oo;
	f[0] = 0;
	for(int i = 1; i <= n; i++){
		long long l = 0, r = n, m, ans = -1;
		while(l <= r){
			m = (l + r) / 2;
			if(a[f[m]] <= a[i]){
				ans = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		//cout << ans << '\n';
		if(a[f[ans + 1]] > a[i]) f[ans + 1] = i;
		res = max(res, ans + 1);
	}
	cout << n - res << '\n';
}