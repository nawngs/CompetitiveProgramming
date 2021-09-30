#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

long long t, f[200005], a[200005], n;

long long mu (long long a, long long b) {
	if (b == 0) return 1;
	long long x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

long long tohop(long long k, long long n) {
	long long a = f[n];
	long long b = (f[n - k] * f[k]) % MOD;
	return ((a % MOD * mu(b, MOD - 2)) % MOD + MOD) % MOD;
}

void sol() {
	cin >> n;
	long long ans = f[n];
	//cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (a[n] == a[n - 1]) {
		cout << ans << '\n';
		return ;
	}
	long long cnt = 0;
	for (int i = 1; i <= n; i++) if (a[i] < a[n] - 1) cnt ++;
	for (int i = 0; i <= cnt; i++) {
		ans = (ans - ((((f[n - i - 1] * f[i]) % MOD) * tohop(i, cnt) % MOD) % MOD) + MOD) % MOD;
		//cout << sum << '\n';
	}
	//cout << sum << '\n';
	cout << ans << '\n';
}

int main () {
	f[0] = 1;
	//f[1] = 1;
	for (int i = 1; i <= 200003; i++) f[i] = (f[i - 1] * i) % MOD;
	//cout << tohop(5, 20) << '\n';
	cin >> t;
	while (t --) sol();
}