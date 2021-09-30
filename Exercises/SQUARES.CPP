#include <bits/stdc++.h>

using namespace std;

const long long MOD = 2013;

long long n, ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ans += 1ll * i * i;
		ans %= MOD;
	}
	cout << ans;
}