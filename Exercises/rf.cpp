#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "rf";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E15;
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll m, n, P, a[1003], b[1003];

ll nhan(ll a, ll b) {
	if (b == 0) return 0;
	ll x = nhan(a, b / 2);
	x = (x + x) % P;
	if (b % 2 == 1) 
		x = (x + a) % P;
	return x;
}

main() {
	fast;
	//fre();
	cin >> m >> n >> P;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int j = 1; j <= n; j++) {
		cin >> b[j];
		for (int i = 1; i <= m; i++) {
			ll g = __gcd(a[i], b[j]);
			a[i] /= g;
			b[j] /= g;
		}
	}
	ll up = 1, down = 1;
	for (int i = 1; i <= m; i++)
		up = nhan(up, a[i]);
	for (int i = 1; i <= n; i++)
		down = nhan(down, b[i]);
	cout << up << '\n' << down << '\n';
}
