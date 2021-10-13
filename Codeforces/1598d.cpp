#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll n, cnt[200005];

pll a[200005];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		cnt[a[i].fi] ++;
	}
	sort(a + 1, a + n + 1, [](pll &x, pll &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se == y.se);
	});
	ll sum2 = 0, sum1 = 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += sum2 * cnt[i];
		sum2 += sum1 * cnt[i];
		sum1 += cnt[i];
	}
	int i = 1;
	while (i <= n) {
		int j = i + 1;
		while (j <= n && a[j].fi == a[i].fi) {
			if (a[j].se == a[i - 1].se) dem ++;
			else {
				temp.push_back({a[j -1].se, dem});
				dem = 1;
			}
			j ++;
		}
		temp.push_back(a[j - 1].se, dem);
		d
	}
	cout << ans << '\n';

}

int main() {
	fastflow;
	int t;
	cin >> t;
	while (t --) sol();
}
