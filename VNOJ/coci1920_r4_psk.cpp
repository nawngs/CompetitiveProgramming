//link:https://oj.vnoi.info/problem/coci1920_r4_psk
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

using namespace std;

ll n, sum = 0, res[1005];

pair < ll, ll > a[1005];

bool cmp(pair < ll, ll > x, pair < ll, ll > y) {
	return (x.fi > y.fi) || (x.fi == y.fi && x.se < y.se);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x >> a[i].fi;
		a[i].se = i;
		sum += x;
	}
	sort(a + 1, a + n + 1, cmp);
	ll sum2 = 0, pos;
	for (int i = 1; i <= n; i++) {
		res[a[i].se] = min(sum - sum2, a[i].fi);
		sum2 += a[i].fi;
		if(sum2 >= sum) {
			pos = i;
			break;
		}
	}
	cout << n - pos << '\n';
	for (int i = 1; i <= n; i++) {
		cout << res[i] << ' ';
	}

}
