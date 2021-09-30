#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll n, a[200005], s[200005], f[10];

pll bs1(ll l, ll r) {
	ll taml = l, tamr = r;
	ll mid, ans = INF;
	pll res;
	while (l <= r) {
		mid = (l + r) / 2;
		if (abs((s[mid] - s[taml - 1]) - (s[tamr] - s[mid])) < ans) {
			ans = abs((s[mid] - s[taml - 1]) - (s[tamr] - s[mid]));
			res.fi = max(s[mid] - s[taml - 1], s[tamr] - s[mid]);
			res.se = min(s[mid] - s[taml - 1], s[tamr] - s[mid]);
		}
		if (s[mid] - s[taml - 1] > s[tamr] - s[mid]) r = mid - 1;
		else l = mid + 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	ll ans = 1e18;
	for (int i = 2; i < n; i++) {
		auto l = bs1(1, i);
		auto r = bs1(i + 1, n);
		ans = min(ans, max(l.fi, r.fi) - min(l.se, r.se));
	}
	cout << ans;
}
