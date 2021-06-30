#include <bits/stdc++.h>

using namespace std;

int n, m1, m2, a[23], sum1 = 0, sum2 = 0, cnt = 0, ans = -1e9;

void sol(int pos){
	for(int i = 0; i <= 2; i++){
		if(i == 1){
			cnt ++;
			sum1 += a[pos];
			if(sum1 > m1){
				cnt --;
				sum1 -= a[pos];
				continue;
			}
		}
		if(i == 2){
			cnt ++;
			sum2 += a[pos];
			if(sum2 > m2){
				cnt --;
				sum2 -= a[pos];
				continue;
			}
		}
		if(pos == n) ans = max(ans, cnt);
		else sol(pos + 1);
		if(i == 1){
			cnt --;
			sum1 -= a[pos];
		}
		if(i == 2){
			cnt --;
			sum2 -= a[pos];
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("XEPDOVAT.INP", "r", stdin);
	freopen("XEPDOVAT.OUT", "w", stdout);
	cin >> n >> m1 >> m2;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	sol(1);
	cout << ans;
}