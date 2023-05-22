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

ll n, a[500003];

pll f[500003];

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	f[0] = f[n + 1] = {-LINF, LINF};
	for (int i = 1; i <= n / 2; i++) {
		f[i].fi = max(f[i - 1].fi, a[i] + a[n - i + 1]);
		f[i].se = min(f[i - 1].se, a[i] + a[n - i + 1]);
		f[n - i + 1] = f[i];
	}
	ll res = f[n / 2].fi - f[n / 2].se;
	pll cur = {-LINF, INF};
	for (int i = n / 2; i >= 1; i--) {
		cur.fi = max(cur.fi, a[i + 1] + a[n - i + 1]);
		cur.se = min(cur.se, a[i + 1] + a[n - i + 1]);
		pll tam;
		tam.fi = max(cur.fi, f[i - 1].fi);
		tam.se = min(cur.se, f[i - 1].se);
		res = min(res, tam.fi - tam.se);
	}
	cur = {-LINF, INF};
	for (int i = n / 2 + 2; i <= n; i++) {
		cur.fi = max(cur.fi, a[i - 1] + a[n - i + 1]);
		cur.se = min(cur.se, a[i - 1] + a[n - i + 1]);
		pll tam;
		tam.fi = max(cur.fi, f[i + 1].fi);
		tam.se = min(cur.se, f[i + 1].se);
		res = min(res, tam.fi - tam.se);
	}
	cout << res;
}
