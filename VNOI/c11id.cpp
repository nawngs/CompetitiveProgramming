//link: https://oj.vnoi.info/problem/c11id

#include <bits/stdc++.h>

using namespace std;

long long n, a[100005], ans = 1;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		ans *= a[i] - i + 1;
		ans %= 1000000007;
	}
	cout << ans;
}