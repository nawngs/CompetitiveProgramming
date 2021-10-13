#include <bits/stdc++.h>

using namespace std;

int n, k, a[100005];

int bs(int val) {
	int l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

bool check(int x) {
	int l = 1;
	for (int i = 1; i <= k; i++) {
		l = bs(a[l] + x);
		//cout << x << " " << l << '\n';
	}
	return (l == n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("Jumfrog.inp", "r", stdin);
	//freopen("Jumfrog.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//check(5682);
	int l = 0, r = 1e9, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}