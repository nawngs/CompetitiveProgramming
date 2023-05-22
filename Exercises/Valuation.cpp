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

const string NAME = "valuation";
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

ll n, f[200003], g[200003];

pll a[200003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].se;
		f[i] = g[i] = -LINF;
	}
	sort(a + 1, a + n + 1, [&](pll &x, pll &y) {
		return x.fi > y.fi || (x.fi == y.fi && x.se > y.se);
	});
	priority_queue < ll, vector < ll >, greater < ll > > heap;
	ll res = 0;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			heap.push(a[i].se);
			res += a[i].se;
		}
		else {
			if (heap.top() < a[i].se) {
				res = res - heap.top() + a[i].se;
				heap.pop();
				heap.push(a[i].se);
			}
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

/*
4
	7 12 1 14 
	20 18 10 5 */
