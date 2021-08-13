//link:	https://drive.google.com/file/d/1FMvsUFzzchU4YIUCY7rt0So7R-frWyKT/view
#include <bits/stdc++.h>

using namespace std;

long long n, a[500005], check[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(check, 0, sizeof(check));
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	//for(long long i =1 ; i <= n; i++) cout << a[i] << " ";
	//cout << '\n';
	long long r = n, res = 0;
	for(int i = n; i >= 1; i--){
		if(check[i]) continue;
		long long temp = (a[i] - (a[i] % 2)) / 2, mid, ans = -1, l = 1;
		while(l <= r){
			mid = (l + r) / 2;
			if(a[mid] <= temp){
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if(ans == -1) continue;
		check[ans] = 1;	
		res ++;
		r = ans - 1;
		//cout << i << " " << ans << '\n';
	}
	cout << n - res;
}