#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e6;

int t, dem[nmax + 5], l, r, k;

bool check[nmax + 5];

void sang() {
	for (int i = 1; i <= nmax; i++) check[i] = true;
	check[1] = check[0] = false;
	for (int i = 2; i * i <= nmax; i++) 
		if (check[i]) for (int j = i * i; j <= nmax; j += i) check[j] = false;
	for (int i = 1; i <= nmax; i++) {
		dem[i] = dem[i - 1] + check[i];
	}
}

void sol() {
	cin >> l >> r >> k;
	long long ans = 0;
	for (int i = l + k; i <= r; i++) if (check[i]) ans += dem[i - k] - dem[l - 1];
	cout << ans << '\n';
}

int main() {
	cin >> t;
	sang();
	while (t --) sol();
}