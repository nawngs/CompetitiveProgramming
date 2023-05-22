#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int ntest;
pair <int, int> a[10005];

bool cmp(pair <int, int> x, pair <int, int>  y){
	return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
}

int main(){
	cin >> ntest;
	while(ntest --){
		int n;
		memset(a, 0, sizeof(a));
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i].fi;
			a[i].se = i;
		}
		sort(a + 1, a + n + 1, cmp);
		int l = 1, sum = a[1].se;
		a[n + 1].fi = -1;
		long long ans = 0;
		for(int i = 2; i <= n + 1; i++){
			if(a[i].fi != a[i - 1].fi){
				sum = 0;
			}
			ans += sum * (n - a[i].se + 1);
			sum += a[i].se;
		}
		cout << ans << '\n';
	}
}