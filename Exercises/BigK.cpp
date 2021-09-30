#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, k, s[500005], minl[500005], maxr[500005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	maxr[n + 1] = -1e18;
	for (int i = 1; i <= n; i++) minl[i] = min(minl[i - 1], s[i]);
	for (int i = n; i >= 0; i--) maxr[i] = max(maxr[i + 1], s[i]);
	ll l = 0, r = 0, ans = 0;;
	while (l <= n && r <= n) {
		//cout << maxr[r] << " " << minl[l] << '\n';
		//cout << l << " " << r << ''
		if (maxr[r] - minl[l] >= k) {
			//cout << l << " " << r << '\n';
			ans = max(ans, r - l);			
			r ++;
		}
		else l ++;
	}
	cout << ans;
}
