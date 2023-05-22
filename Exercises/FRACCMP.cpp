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

const string NAME = "FRACCMP";
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

ll a, b, c, d;

ll sosanh(ll a, ll b, ll c, ll d) {
	ll tam1 = a / b;
	ll tam2 = c / d;
	if (tam1 > tam2) return 1;
	if (tam1 < tam2) return -1;
	a %= b;
	c %= d;
	if (a == 0 && c == 0) return 0;
	if (a == 0 &&  c != 0) return -1;
	if (a != 0 && c == 0) return 1;
	return -sosanh(b, a, d, c);
}

void sol() {
	cin >> a >> b >> c >> d;
	cout << sosanh(a, b, c, d) << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
