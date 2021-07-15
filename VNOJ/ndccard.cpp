//link: https://oj.vnoi.info/problem/ndccard
// 2 pointers

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, a[10005], ans = -1e18;

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll i = 1, j = n, mid = n - 1;
	while(j - i + 1 >= 3){
		//cout << i << " " << j << '\n';
		if(a[i] + a[i + 1] + a[j] > m){
			j --;
			continue;
		}
		ll mid = i + 1;
		while(1){
			if(a[i] + a[j] + a[mid] <= m){
				ans = max(ans, a[i] + a[mid] + a[j]);
				break;
			}
			mid --;
		}
		i ++;
	}
	cout << ans;
}