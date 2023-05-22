#include <bits/stdc++.h>

using namespace std;

const long long oo = 1e18;
long long n, a[300005], f[300005], res = -oo, dp[300005], pos, k;
vector < long long > vec;

int main(){
	cin >> n >> k;
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
		dp[i] = f[ans];
		if(a[f[ans + 1]] > a[i]){
			f[ans + 1] = i;
			if(res < ans + 1){
				res = ans + 1;
				pos = i;
			}
		}
	}
	if (res >= k) {
		while(pos != 0){
			vec.push_back(pos);
			pos = dp[pos];
		}
		sort(vec.begin(), vec.end());
		for(int i = 0; i < k; i++) cout << a[vec[i]] << ' ';
		return 0;
	}
	reverse(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) f[i] = n + 1;
	a[n + 1] = oo;
	a[0] = -oo;
	f[0] = 0;
	for(int i = 1; i <= n; i++){
		long long l = 0, r = n, m, ans = -1;
		while(l <= r){
			m = (l + r) / 2;
			if(a[f[m]] < a[i]){
				ans = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		//cout << ans << '\n';
		dp[i] = f[ans];
		if(a[f[ans + 1]] > a[i]){
			f[ans + 1] = i;
			if(res < ans + 1){
				res = ans + 1;
				pos = i;
			}
		}
	}
	if (res >= k) {
		while(pos != 0){
			vec.push_back(pos);
			pos = dp[pos];
		}
		for(int i = 0; i < k; i++) cout << n - a[vec[i]] + 1 << ' ';
		return 0;
	}

}