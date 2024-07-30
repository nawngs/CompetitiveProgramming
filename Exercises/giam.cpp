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

const string NAME = "lis";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[1220800], f[1220800];

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = -INF;
	}	
	f[0] = INF;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		ll l = 0, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (f[mid] > a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		res = max(res, ans + 1);
		f[ans + 1] = max(f[ans + 1], a[i]);
	}
	cout << res;
}
