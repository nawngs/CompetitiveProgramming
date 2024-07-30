#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "digits";
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

ll a, b, c;

int main() {
	fast;
	fre();
	cin >> a >> b >> c;
	if (a == 0 && c == 1) {
		cout << a << '\n';
		return 0;
	}
	ll lim = 9, cnt = 1;
	while (lim < a) {
		lim = lim * 10 + 9;
		cnt ++;
	}
	while (1) {
		ll sub = (lim - a) / b + 1;
		if (sub * cnt < c) {
			c -= sub * cnt;
			lim = lim * 10 + 9;
			cnt ++;
			a += sub * b;
			continue;
		}
		ll l = a, r = lim, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			ll tam = (mid - a) / b + 1;
			if (tam * cnt < c) l = mid + 1;
			else {
				ans = mid;
				r = mid - 1;
			}
		}
		sub = (ans - a) / b;
		c -= sub * cnt;
		vector < int > dg;
		while (ans > 0) {
			dg.push_back(ans % 10);
			ans /= 10;
		}
		reverse(dg.begin(), dg.end());
		for (int i = 0; i < c; i++) cout << dg[i];
		return 0;
	}
}
