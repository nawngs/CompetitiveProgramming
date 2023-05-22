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

ll n, m, c[100003], w[100003];

pll res[100003];

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		res[i].fi = c[i] / 100;
	}
	for (int i = 1; i <= n; i++) 
		cin >> w[i];
	ll total = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	for (int i = 1; i <= n; i++) {
		res[i].se = c[i] % 100;
		if (res[i].se == 0) continue;
		heap.push({w[i] * (100 - res[i].se), i});
		m -= res[i].se;
		if (m < 0) {
			auto x = heap.top();
			heap.pop();
			total += x.fi;
			res[x.se].fi ++; res[x.se].se = 0;
			m += 100;
		}
	}
	cout << total << '\n';
	for (int i = 1; i <= n; i++)
		cout << res[i].fi << " " << res[i].se << '\n';
}
