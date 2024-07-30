#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = 1e6;
const ll LINF = 1e16;

ll n, m, a[N + 3], b[N + 3];

bool check(ll x) {
	int l = 1;
	for (int i = 1; i <= n; i++) {
		while (l <= m && a[i] + b[l] < x) l ++;
		if (a[i] + b[l] < x) return false;
		if (a[i] < x) l ++;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("b3.inp", "r", stdin);
	freopen("b3.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	ll l = 0, r = 1e16, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
}