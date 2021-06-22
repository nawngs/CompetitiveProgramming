#include <bits/stdc++.h>

using namespace std;

long long n, d, a[100005];

int main(){
	freopen("radiseq.inp", "r", stdin);
	freopen("radiseq.out", "w", stdout);
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(a[n] - a[1] <= d){
		cout << a[n] - a[1] << '\n' << 0 << "\n";
	}
	else{
		cout << a[n] - a[1] << "\n";
		a[n + 1] = 1e18;
		long long cuoi = 2, ans = 1e18;
		for(int i = 1; i <= n; i++){
			while(a[cuoi] - a[i] <= d) cuoi ++;
			cuoi --;
			//cout << cuoi << '\n';
			ans = min(ans,  i - 1 + n  - cuoi);
		}
		cout << ans << '\n';
	}
}