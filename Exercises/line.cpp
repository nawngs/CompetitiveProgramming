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

const string NAME = "line";
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

int n, res = 0;

pii a[1003];

map < pii, int > f;

void sol() {
	cin >> n;
	res = 0;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	int dem = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i].fi == a[i - 1].fi) dem ++;
		else {
			res = max(res, dem);
			dem = 1;
		}
	}
	res = max(res, dem);
	sort(a + 1, a + n + 1, [&](pii &x, pii &y) {
		return x.se < y.se;
	});
	dem = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i].se == a[i - 1].se) dem ++;
		else {
			res = max(res, dem);
			dem = 1;
		}
	}
	res = max(res, dem);
	f.clear();
	for (int i = 1; i <= n; i++) {
		f.clear();
		for (int j = i + 1; j <= n; j++) {
			if (a[i].fi == a[j].fi || a[i].se == a[j].se) continue;
			pii tam = make_pair(a[j].fi - a[i].fi, a[j].se - a[i].se);
			int temp = __gcd(tam.fi, tam.se);
			tam.fi /= temp;
			tam.se /= temp;
			f[tam] ++;
			res = max(res, f[tam] + 1);
		}
	}
	cout << res << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
