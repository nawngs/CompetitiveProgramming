#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

long long n;

pair < long long, long long > a[100005];

bool cmp(pair < long long, long long > x, pair < long long, long long > y){
	return (x.se < y.se) || (x.se == y.se && x.fi < y.fi);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, cmp);
	//cout << a[1].se << '\n';
	//cout << ans << '\n';
	long long pos = n, ans = 0, tam = 0;
	while(tam < a[1].se && pos > 1){
	//	cout << tam << '\n';	
		if(tam + a[pos].fi <= a[1].se){
			tam += a[pos].fi;
			a[pos].fi = 0;
			ans += a[pos].fi * 2;
			pos --;
		}
		else{
			a[pos].fi -= a[1].se - tam;
			ans += 2 * (a[1].se - tam);
			tam = a[1].se;
		}
	}
	//cout << ans << '\n';
	//cout << "YEs" << '\n';
	for(int i = 1; i <= n; i++){
		//cout << a[i].fi << " " << a[i].se << '\n';
		//ans += min(a[i].fi * 2, a[i].fi + max((long long) 0, a[i].se - tam));
		if(a[i].fi * 2 <= a[i].fi + max((long long) 0, a[i].se - tam)){
			ans += a[i].fi * 2;
			tam += a[i].fi;
		}
		else{
			ans += a[i].fi + max((long long) 0, a[i].se - tam);
			tam += a[i].fi + max((long long) 0, a[i].se - tam);
		}
	}
	cout << ans;
}