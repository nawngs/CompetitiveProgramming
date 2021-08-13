//link: https://drive.google.com/file/d/1Q2dlmOECROS-lksHYhAVft0w8SVu3GlY/view
#include <bits/stdc++.h>

using namespace std;

long long n, a[100005], k;

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = 0;
	int l = 1;
	while(1){
		//cout << l << '\n';
		int cnt = 0;
		int r = l;
		while(a[r] == a[l]){
			r ++;
			cnt ++;
		}
		//cout << cnt << '\n';
		if(sum + cnt * n >= k){
			cout << a[l] << " " << a[(k - sum + cnt - 1) / cnt] ;
			return 0;
		}
		sum += cnt * n;
		l = r;
	}
}