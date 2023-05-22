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

int n, m;

pii a[100003];

map < pii, int > f;

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].fi >> a[i].se;
		if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
	}
	sort(a + 1, a + m + 1);
	int ans = 1;
	for (int i = 1; i <= m; i++) {
		pii temp = {a[i].fi - 1, a[i].se + 1};
		int v = f[temp] + 1;
		f[a[i]] = v;
		if (a[i].se - a[i].fi <= 2) ans = max(ans, a[i].se - a[i].fi + 2 * v - 1);
	}
	cout << ans;
}
