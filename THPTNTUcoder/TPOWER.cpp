//link: http://thptchuyen.ntucoder.net/ckfinder/userfiles/files/TPOWER.pdf
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, k, a[100005], pow2[35], res[100005];

void build_arr(){
	pow2[0] = 1;
	for(int i = 1; i <= 33; i++) pow2[i] = pow2[i - 1] * 2;
}

ll bs1(ll x){
	ll l = 1, r = n, mid, ans = -1;
	while(l <= r){
		mid = (l + r) / 2;
		if(a[mid] >= x){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

ll bs2(ll x){
	ll l = 1, r = n, mid, ans = -1;
	while(l <= r){
	 mid = (l + r) / 2;
		if(a[mid] <= x){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int main(){
	build_arr();
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 35; j++){
			if(a[i] >= pow2[j]) continue;
			ll tmp = pow2[j] - a[i];
			ll pos1 = bs1(tmp);
			ll pos2 = bs2(tmp);
			if(pos1 == -1 || a[pos1] != tmp || pos2 == -1 || a[pos2] != tmp) continue;
			res[j] += pos2 - pos1 + 1 - (pos1 <= i && i <= pos2);
		}
	}
	for(int i = 1; i <= k; i++) cout << res[i] / 2 << "\n";
}