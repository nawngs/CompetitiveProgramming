#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, a[100005], q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	//ll q;
	//cin >> q;
	while(q --){
		ll x;
		cin >> x;
		ll l = 1, r = n, mid, pos = n + 1;
		while(l <= r){
			mid = (l + r) / 2;
			if(a[mid] >= x){
				pos = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ll temp = pos - 1, ans = n - pos + 1;
		for(int i = pos - 1; i >= 1; i--){
			temp --;	
			if(a[i] + temp >= x){
				ans ++;
				temp -= x - a[i];
			}
			else break;
		}
		cout << ans << '\n';
	}
}

