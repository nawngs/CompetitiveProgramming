//link: https://oj.vnoi.info/problem/nksgame
// 2 pointers

#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, b[100005], c[100005], ans = 1e18;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int j = 1; j <= n; j++) cin >> c[j];
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	ll i = 1, j = n;
	while(1){
		if(i == n + 1 || j == 0) break;
		//cout << i << " " << j << '\n';
		while(1){
			if(j == 0) break;
			ans = min(ans, abs(b[i] + c[j]));
			if(b[i] + c[j] < 0) break;
			else j --;
		}
		i ++;
	}
	cout << ans << '\n';
}
