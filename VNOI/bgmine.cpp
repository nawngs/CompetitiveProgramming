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
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, x[100003], g[100003], r[100003], sr[100003], sg[100003];

void sol() {
	cin >> n;
	vector < pair < pll, ll > > tam;
	tam.clear();
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> g[i] >> r[i];
		sr[i] = sr[i - 1] + r[i];
		sg[i] = sg[i - 1] + g[i];
		tam.push_back({{sr[i] - x[i], 2}, i});
		tam.push_back({{sr[i - 1] - x[i], 1}, i});
	}
	sort(tam.begin(), tam.end());
	ll pos = INF;
	ll ans = 0;
	for (int i = 0; i < tam.size(); i++) {
		if (tam[i].fi.se == 1) pos = min(pos, tam[i].se);
		else if (pos != INF  && pos <= tam[i].se) ans = max(ans, sg[tam[i].se] - sg[pos - 1]);
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
