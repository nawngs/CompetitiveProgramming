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

const string NAME = "angle2";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const ld pi = acos(-1);

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ld a, b, c, d;

int main() {
	fast;
	fre();
	cin >> a >> b >> c >> d;
	ld val = (a * c + b * d) / (sqrtl(a * a + b * b) * sqrtl(c * c + d * d));
	ld res = acos(val);
	cout << fixed << setprecision(9) << res;	
}