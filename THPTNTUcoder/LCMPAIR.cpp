// link: http://thptchuyen.ntucoder.net/ckfinder/userfiles/files/LCMPAIR.pdf

#include <bits/stdc++.h>

using namespace std;

long long n, a[100005];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	long long  ans = 0;
	long long cnt = 1;
	a[n + 1] = -1e9;
	for(int i = 2; i <= n + 1; i++){
		if(a[i] == a[i - 1]) cnt ++;
		else{
			ans += cnt * (cnt - 1) / 2;
			cnt = 1;
		}
	}
	cout << ans;
}