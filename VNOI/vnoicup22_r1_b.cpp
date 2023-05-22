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

int n, dem[1000003], res[1000003];

pii a[1000003];

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].fi;
		a[i].se = i;
		dem[a[i].fi] ++;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		if (i != 1 && a[i].fi == a[i - 1].fi) res[a[i].se] = res[a[i - 1].se];
		else for (int j = 2 * a[i].fi; j <= 1e6; j += 2 * a[i].fi) res[a[i].se] += dem[j];
	}
	for (int i = 1; i <= n; ++i) cout << (1ll * res[i] * 1ll * (res[i] - 1)) / 2 << ' ';
}
