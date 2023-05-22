#include <bits/stdc++.h>

#define int long long

using namespace std;

const long long MOD = 1E9 + 7;

int n, a[1003], res = 0,val1 = 0, val2 = 0, mu[1003];

void back_track(int pos) {
	if (pos == n + 1) {
		res += (val1 == val2);
		return ;
	}
	for (int i = 1; i <= 2; i++) {
		if (i == 1) val1 ^= a[pos];
		else val2 ^= a[pos];
		back_track(pos + 1);
		if (i == 1) val1 ^= a[pos];
		else val2 ^= a[pos];
	}
}

signed main() {
	cin >> n;
	mu[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] ^= a[i - 1];
		mu[i] = (mu[i - 1] * 2) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] == a[j]) res = (res + mu[i - j - 1] - 1) % MOD;
		}
	}
	cout << res;
}