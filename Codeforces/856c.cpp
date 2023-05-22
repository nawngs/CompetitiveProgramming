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
const pll base = {2309, 9851};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}


pll Pow[1000003], val[1000003];

ll n, m;

pll edges[1000003];

void add(pll &x, pll y) {
	x.fi += y.fi;
	x.se += y.se;
}

int main() {
	fast;
	//fre();
	cin >> n >> m;
	Pow[0] = {1, 1};
	for (int i = 1; i <= n; i++) 
		Pow[i].fi = Pow[i - 1].fi * base.fi, Pow[i].se = Pow[i - 1].se * base.se;
	for (int i = 1; i <= m; i++) {
		ll u, v; cin >> u >> v;
		add(val[u], Pow[v]); add(val[v], Pow[u]);
 		edges[i] = {u, v};
 	}
 	vector < pll > Love;
 	for (int i = 1; i <= n; i++)
 		Love.push_back(val[i]);
 	sort(Love.begin(), Love.end());
 	ll cnt = 1, res = 0;
 	for (int i = 1; i < Love.size(); i++) {
 		if (Love[i] == Love[i - 1]) cnt ++;
 		else {
 			res = res + cnt * (cnt - 1) / 2;
 			cnt = 1;
 		}
 	}
 	res = res + cnt * (cnt - 1) / 2;
 	for (int i = 1; i <= m; i++) {
 		ll u = edges[i].fi, v = edges[i].se;
 		add(val[u], Pow[u]); add(val[v], Pow[v]);
 		if (val[u] == val[v]) res ++;
 		add(val[u], {-Pow[u].fi, -Pow[u].se});
 		add(val[v], {-Pow[v].fi, -Pow[v].se});
 	}
 	cout << res;
}
