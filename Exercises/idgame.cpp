#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "idgame";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[1000003], s[1000003], q, d;

bool check(ll x) {
	int l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] * mid - s[mid] <= x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	ll rem = x - (a[ans] * ans - s[ans]);
	ll h1 = a[ans] + rem / ans;
	l = 1, r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		if (s[n] - s[mid - 1] - a[mid] * (n - mid + 1) <= x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	rem = x - (s[n] - s[ans - 1] - a[ans] * (n - ans + 1));
	ll h2 = a[ans] - rem / (n - ans + 1);
	return h2 - h1 <= d;
}

int main() {
	fast;
	fre();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	while (q--) {
		cin >> d;
		ll l = 0, r = 1e15, mid, ans;
		check(1);
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
}
