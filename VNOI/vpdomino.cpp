//link: https://oj.vnoi.info/problem/vpdomino
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll n, demp = 0, dp[500005], ans = 0;
pair < ll, ll > a[200005];
pair < ll, pair < ll, ll > > p[500005];

bool cmp(pair < ll, ll > x, pair < ll, ll > y){
	return (x.se < y.se) || (x.se == y.se && x.fi < y.fi);
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi >> a[i].se;
		p[++ demp].fi = a[i].fi;
		p[demp].se.fi = i;
		p[demp].se.se = 1;
		p[++ demp].fi = a[i].se;
		p[demp].se.fi = i;
		p[demp].se.se = 2;
	}
	sort(p + 1, p + demp + 1);
	p[0].fi = 1e18;
	ll dem = 0;
	for(int i = 1; i <= demp; i++){
		if(p[i].fi != p[i - 1].fi) dem ++;
		if(p[i].se.se == 1) a[p[i].se.fi].fi = dem;
		else a[p[i].se.fi].se = dem;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		dp[a[i].se] = dp[a[i].fi] + 1;
		ans = max(ans, dp[a[i].se]);
	}
	cout << ans;
}