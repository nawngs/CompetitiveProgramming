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

const string NAME = "";
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

ll n;

ll dp[1000003];

pll a[4];

vector < pll > tmp1, tmp2;

ll calc(ll n, vector < pll > c) {
	if (c.size() == 0) return n;
	if (c.size() == 1) return (n / c[0].fi) * c[0].se + (n % c[0].fi); 
	ll res = n;
	for (int i = 0; i < c[1].fi; i++) {
		if (n < i * c[0].fi) break;
		ll tam = i * c[0].se;
		ll new_n = n - i * c[0].fi;
		res = max(res, tam + (new_n / c[1].fi) * c[1].se + (new_n % c[1].fi));
	}
	return res;
}

int main() {
	fast;
	cin >> n >> a[1].fi >> a[2].fi >> a[3].fi >> a[1].se >> a[2].se >> a[3].se;
	bool th1 = true;
	for (int i = 1; i <= 3; i++) 
		if (a[i].fi < a[i].se) {
			th1 = false;
			break;
		}
	bool th2 = true;
	for (int i = 1; i <= 3; i++) 
		if (a[i].fi > a[i].se) {
			th2 = false;
			break;
		}
	if (th1 || th2) {
		for (int i = 1; i <= 3; i++) if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
		
		for (int i = 1; i <= n; i++) dp[i] = -LINF;
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) 
				if (i >= a[j].fi) dp[i] = max(dp[i], dp[i - a[j].fi] + a[j].se);	
			//cout << i << " " << dp[i] << '\n';
		}
		cout << dp[n] << '\n';
		return 0;
	}
	sort(a + 1, a + 4, [&](pll &x, pll &y) {
		return x.se * y.fi < x.fi * y.se;
	});
	for (int i = 1; i <= 3; i++) {
		if (a[i].se > a[i].fi) tmp1.push_back({a[i].fi, a[i].se});
		swap(a[i].fi, a[i].se);
	}
	sort(a + 1, a + 4, [&](pll &x, pll &y) {
		return x.se * y.fi < x.fi * y.se;
	});
	for (int i = 1; i <= 3; i++) 
		if (a[i].se > a[i].fi) tmp2.push_back({a[i].fi, a[i].se});
	cout << calc(calc(n, tmp1), tmp2);
}
