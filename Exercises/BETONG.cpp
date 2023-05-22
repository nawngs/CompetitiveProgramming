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

const string NAME = "BETONG";
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

int n;
pii a[1000003];

bool check[1000003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	int dem = 0, ans = 0;
	sort(a + 1, a + n + 1, [](pii &x, pii &y) {
		return x.fi > y.fi;
	});
	a[++ n].fi = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i].fi != a[i - 1].fi) ans = max(ans, dem);
		if (!check[a[i].se - 1] && !check[a[i].se + 1]) dem ++;
		if (check[a[i].se - 1] && check[a[i].se + 1]) dem --;
		check[a[i].se] = true;
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
