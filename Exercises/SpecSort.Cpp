#include <bits/stdc++.h>

using namespace std;

int n, a[100005], b[100005], c[100005], ans = 0;

int bs(int a[], int val, int l) {
	int r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] > val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	int lb = 1, lc = 1;
	for (int i = 1; i <= n; i++) {
		lb = bs(b, a[i], lb);
		if (lb == -1) {
			cout << ans << '\n';
			return 0;
		}
		lc = bs(c, b[lb], lc);
		if (lc == -1) {
			cout << ans << '\n';
			return 0;
		}
		//cout << i << " " << lb << " " << lc << '\n';
		lb ++;
		lc ++;
		ans ++;
	}	
}