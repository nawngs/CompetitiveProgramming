//link: https://oj.vnoi.info/problem/fc128_strict
#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

const int MOD = 1E9 + 7;
long long n, a[200005], cnt[200005], ans = 1;
pair < long long, long long > p[200005];

int main(){
	cin >> n;
	//cout << nhan(3, 2) << '\n';
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p[i].fi = a[i];
		p[i].se = i;
		//cnt[a[i]] ++;
	}
	sort(p + 1, p + n + 1);
	int dem = 0;
	p[0].fi = 1e18;
	for(int i = 1; i <= n; i++){
		if(p[i].fi != p[i - 1].fi) dem ++;
		//a[p[i].se] = dem;
		cnt[dem] ++;
	}
	for(int i = 1; i <= n; i++){
		//cout << cnt[i] << '\n';
		ans = ans * (cnt[i] + 1);
		ans %= MOD;
		//cout << ans << '\n';
	}
	cout << ans;
}