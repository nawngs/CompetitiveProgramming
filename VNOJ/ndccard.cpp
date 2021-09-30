#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll n, m, a[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for (int i = 1; i < n - 1; i++) {
		ll j = i + 1, k = n;
		while (j < k) {
			while (j < k && a[i] + a[j] + a[k] > m) k --;
			while (j < k && a[i] + a[j] + a[k] <= m) {
				//cout << a[i] << " " << a[j] << " " << a[k] << '\n';
				ans = max(ans, a[i] + a[j] + a[k]);
				j ++;
			}
		}
	}
	cout << ans;
}
