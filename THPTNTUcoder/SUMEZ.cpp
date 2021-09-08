#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000;

long long n, x, ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		x %= MOD;
		ans += x;
		ans %= MOD;
	}
	cout << ans % MOD + 7;
}
    