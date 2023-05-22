#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "xeptrung";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, a[100005], s[100005];

bool check(ll x) {
	ll cnt = 0;
	ll i = 0;
	while (i < n) {
		ll l = i + 1, r = n, mid, ans = -1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (s[mid] - s[i] <= x) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (ans == -1) return false;
		cnt ++;
		i = ans;
	}
	return cnt <= m;
}

void sol() {
	cin >> n >> m;
	ll maxa = -INF;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxa = max(maxa, a[i]);
		s[i] = s[i - 1] + a[i];
	}
	ll l = maxa, r = s[n], mid, ans;
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

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
