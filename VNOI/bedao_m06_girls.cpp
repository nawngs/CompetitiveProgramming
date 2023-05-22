#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, a[1000005], m, k, s[1000005], ans = -2;

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = m; i <= n; i++) {
		if (a[i] - a[i - m + 1] <= k) {
			ans = max(ans, s[i] - s[i - m]);
		}
	}
	cout << ans;
}
