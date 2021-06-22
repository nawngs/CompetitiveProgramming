#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

long long n, demr = 0;
pair < long long , long long > a[100005], res[100005];

bool cmp(pair < long long , long long > x, pair < long long , long long >  y){
	return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
}

int main(){
	freopen("MergSeg.inp", "r", stdin);
	freopen("MergSeg.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi >> a[i].se;
	}
	sort(a + 1, a + n + 1, cmp);
	a[n + 1].fi = 1e18;
	a[n + 1].se = 1e18;
	long long dau = a[1].fi;
	long long cuoi = a[1].se;
	for(int i = 2; i <= n + 1; i++){
		if(a[i].fi > cuoi){
			res[++ demr].fi = dau;
			res[demr].se = cuoi;
			dau = a[i].fi;
			cuoi = a[i].se;
		}
		else{
			dau = min(dau, a[i].fi);
			cuoi = max(cuoi, a[i].se);
		}
	}
	cout << demr << '\n';
	for(int i = 1; i <= demr; i++) cout << res[i].fi << " " << res[i].se << "\n";
}