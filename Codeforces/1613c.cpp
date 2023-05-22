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

const string NAME = "";
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

ll n, h, a[105];

bool check(ll k) {
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		//cout << k << " " << a[i + 1] - a[i] << '\n';
		res += min(k, a[i + 1] - a[i]);
	}
	//cout << k << " " << res << '\n';
	return (res >= h);
}

void sol() {
	cin >> n >> h;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = INF;
	ll l = 0, r = 1e18, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
