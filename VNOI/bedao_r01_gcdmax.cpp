#include <bits/stdc++.h>

using namespace std;

long long n, a[1000006], gcdl[1000006], gcdr[1000006];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 1) {
		cout << 1000000000 << '\n';
		return 0;
	}
	gcdl[1] = a[1];
	for (int i = 2; i <= n; i++) gcdl[i] = __gcd(gcdl[i - 1], a[i]);
	gcdr[n] = a[n];
	for (int i = n - 1; i >= 1; i--) gcdr[i] = __gcd(gcdr[i + 1], a[i]);
	long long ans = max(gcdl[n - 1], gcdr[2]);
	for (int i = 2; i < n; i++) 
		ans = max(ans, __gcd(gcdl[i - 1], gcdr[i + 1]));
	
	cout << ans;
}