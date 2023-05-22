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

const string NAME = "nhanpham";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 3e9;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, s[100003];

int main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		s[i] = s[i - 1] + x;
		if (i * (i + 1) / 2 - s[i] >= k) {
			cout << i << '\n';
			return 0;
		}
	}	
	ll res = LINF;
	for (ll i = 1; i <= n; i++) {
		ll l = 1, r = base / n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			ll last = mid * n;
			if (last * (last + 1) / 2 - s[n] * mid + i * (i + 1) / 2 + n * mid * i - s[i] >= k) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		res = min(res, ans * n + i);
	}
	cout << res;
	
}
