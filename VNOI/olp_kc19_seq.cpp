#include <bits/stdc++.h>

using namespace std;

long long n, a[100005], x, g[100005][22], q, log2_n;

int main() {
	cin >> n >> q;
	log2_n = log2(n) + 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = abs(a[i] - x);
	}

	for (int i = 1; i <= n; i++) g[i][0] = a[i];

	for (int j = 1; j <= log2_n; j++) 
		for (int i = 1; i <= n; i++) if (i + (1 << (j - 1)) <= n) g[i][j] = __gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);

	while (q --) {
		int l, r;
		cin >> l >> r;
		int k = log2(r - l + 1);
		cout << __gcd(g[l][k], g[r - (1 << k) + 1][k]) << '\n';
	}
}