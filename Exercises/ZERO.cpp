#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e6;

int t, f[nmax + 5], dem = 0;

void build_f() {
	for (int i = 1; i <= nmax; i++) f[i] = i;
	for (int i = 2; i <= nmax; i++) {
		f[i + 1] = min(f[i + 1], f[i] + 1);
		for (int j = 2; i * j <= nmax; j ++) {
			if (j > i) break;
			f[i * j] = min(f[i * j], f[i] + 1);
		}
	}
	//cout << dem;
	//for (int i = 2; i <= nmax; i++) f[i] = min(f[i], f[i - 1] + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("ZERO.inp", "r", stdin);
	freopen("ZERO.out", "w", stdout);
	build_f();
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		cout << f[n] << '\n';
	}
}