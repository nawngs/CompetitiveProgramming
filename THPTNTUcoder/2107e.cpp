#include <bits/stdc++.h>

using namespace std;

long long n, a[100005], l1[100005], l2[100005], r1[100005], r2[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	a[0] = -1e18;
	a[n + 1] = 1e18;
	for(int i = 1; i <= n; i++) cin >> a[i];
	l1[1] = 1;
	l2[1] = 1;
	for(int i = 2; i <= n; i++){
		if(a[i] > a[i - 1]) l1[i] = l1[i - 1] + 1;
		else l1[i] = 1;
		l2[i] = l1[i - 1] + 1;
	}
	r1[n] = 0;
	r2[n] = 0;
	for(int i = n - 1; i >= 1; i --){
		if(a[i] < a[i + 1]) r1[i] = r1[i + 1] + 1;
		else r1[i] = 0;
		if(a[i - 1] + 1 < a[i + 1]) r2[i] = r1[i + 1] + 1;
		else r2[i] = 0;
	}
	long long ans = 1;
	for(int i = 1; i <= n; i++){
		//cout << i << " " << l2[i] << " " << r2[i] << '\n';
		ans = max(ans, l2[i] + r2[i]);
	}
	memset(l2, 0, sizeof(l2));
	memset(r2, 0, sizeof(r2));
	for(int i = 1; i <= n; i++){
		if(a[i + 1] - 1 > a[i - 1]) l2[i] = l1[i - 1] + 1;
		else l2[i] = 1;
	}

	r1[n] = 0;
	for(int i = n - 1; i >= 1; i--) r2[i] = r1[i + 1] + 1;

	for(int i = 1; i <= n; i++){
		//cout << i << " " << l2[i] << " " << r2[i] << '\n';
		ans = max(ans, l2[i] + r2[i]);
	}
	cout << ans;
}