#include <bits/stdc++.h>

using namespace std;

int n, m, a[100003], b[100003];

int bs1(int x) {
	int l = 1, r = n, mid, ans = 2e9 + 7;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] <= x) {
			ans = a[mid];
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int bs2(int x) {
	int l = 1, r = n, mid, ans = -(2e9 + 7);
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] >= x) {
			ans = a[mid];
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		int tam1 = bs1(b[i]);
		int tam2 = bs2(b[i]);
		cout << min(abs(tam1 - b[i]), abs(tam2 - b[i])) << '\n';
	}
}