#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, a[100006], maxl[100006], maxr[100006];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	maxl[0] = -1e18;
	maxr[n + 1] = -1e18;
	for (int i = 1; i <= n; i++) maxl[i] = max(maxl[i - 1], a[i]);
	for (int i = n; i >= 1; i--) maxr[i] = max(maxr[i + 1], a[i]);
	ll ans = -1e18;
	for (int i = 2; i < n; i++) ans = max(ans, -a[i] + maxl[i - 1] + maxr[i + 1]);
	cout << ans;
}
