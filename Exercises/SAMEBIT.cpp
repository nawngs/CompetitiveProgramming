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

const string NAME = "samebit";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 123456789;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll mu(ll a, ll b, ll m) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2, m);
	x = (x * x) % m;
	if (b % 2 == 1) x = (x * a) % m;
	return x;
}

ll n;

void sol() {
	cin >> n;
	ll tam = 3 * MOD;
	if (n % 2 == 1) cout << ((mu(2, n, tam) - 2 + tam) % tam) / 3 << '\n';
	else cout << ((mu(2, n, tam) - 1 + tam) % tam) / 3 << '\n';

}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
