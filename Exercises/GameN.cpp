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

const string NAME = "GameN";
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

ll n, mina[100005], maxa[100005], res[100005];

pair < ll, pll > a[100005];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se.se = i;
	}
	for (int i = 1; i <= n; i++) cin >> a[i].se.fi;
	sort(a + 1, a + n + 1, [](pair < ll, pll > &x, pair < ll, pll > &y) {
		return x.se.fi > y.se.fi;
	});
	res[a[1].se.se] = 1;
	maxa[n] = a[n].fi;
	for (int i = n - 1; i >= 1; i--) maxa[i] = max(maxa[i + 1], a[i].fi);
	mina[1] = a[1].fi;
	res[a[1].se.se] = 1;
	for (int i = 2; i <= n; i++) {
		if (maxa[i] > mina[i - 1]) mina[i] = min(mina[i - 1], a[i].fi);
		else mina[i] = mina[i - 1];
		res[a[i].se.se] = maxa[i] > mina[i - 1];
	}
	for (int i = 1; i <= n; i++) cout << res[i];
	cout << '\n';

}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
