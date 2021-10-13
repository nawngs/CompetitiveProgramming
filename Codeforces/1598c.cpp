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
 
ll n;
ld a[200005], s = 0;
 
ll bs1(ld val, ll taml, ll tamr) {
	ll l = taml, r = tamr, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
} //tim gtln be hon
 
ll bs2(ld val, ll taml, ll tamr) {
	ll l = taml, r = tamr, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] >= val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
} //tim gtnn lon hon
 
 
void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	s = 0;
	for (int i = 1; i <= n; i++) s = s + a[i];
	ld k = (ld) s / n * 2;
	ld tam = k;
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		ll tamr = bs1(tam - a[i], i + 1, n);
		ll taml = bs2(tam - a[i], i + 1, n);
		if (taml == -1 || tamr == -1) continue;
		if (a[taml] + a[i] == tam && a[tamr] + a[i] == tam)  cnt += tamr - taml + 1;
	}
	cout << cnt << '\n';
}
 
int main() {
	fastflow;
	int t;
	cin >> t;
	while (t --) sol();
}