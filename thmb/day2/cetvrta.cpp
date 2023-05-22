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

const string NAME = "cetvrta";
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

int a, b, c, d, e, f;

int main() {
	fast;
	cin >> a >> b >> c >> d >> e >> f;
	pii A = {min(a, min(c, e)), min(b, min(d, f))};
	pii B = {min(a, min(c, e)), max(b, max(d, f))};
	pii C = {max(a, max(c, e)), min(b, min(d, f))};
	pii D = {max(a, max(c, e)), max(b, max(d, f))};
	if (A != make_pair(a, b) && A != make_pair(c, d) && A != make_pair(e, f)) {
		cout << A.fi << " " << A.se << '\n';
		return 0;
	}
	if (B != make_pair(a, b) && B != make_pair(c, d) && B != make_pair(e, f)) {
		cout << B.fi << " " << B.se << '\n';
		return 0;
	}
	if (C != make_pair(a, b) && C != make_pair(c, d) && C != make_pair(e, f)) {
		cout << C.fi << " " << C.se << '\n';
		return 0;
	}
	cout << D.fi << " " << D.se << '\n';
}
