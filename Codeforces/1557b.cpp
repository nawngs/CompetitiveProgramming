#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
 
long long t, n, k;
 
pair < long long, long long > a[100005];
 
int main(){
	//cout << (0 & 0 & 1) << '\n';
	cin >> t;
	while(t --){
		cin >> n >> k;	
		for(int i = 1; i <= n; i++){
			cin >> a[i].fi;
			a[i].se = i;
		}
		sort(a + 1, a + n + 1);
		long long i = 1, cnt = 0;
		a[0].fi = 1e9 + 7;
		a[n + 1].fi = 1e9 + 7;
		while(i <= n){
			int j = i + 1;
			int r = a[i].se;
			while(j <= n){
				if(a[j].se == r + 1){
					r ++;
					j ++;
					continue;
				}
				else break;
			}
			i = j;
			cnt ++;
		}
		if(cnt <= k) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
}