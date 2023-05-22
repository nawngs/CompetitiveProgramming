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

const string NAME = "intsle";
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

ll a1, b1, c1, a2, b2, c2, res, pos, pos2;

void sol() {
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	res = 0, pos2 = 0;
	for (int x1 = -1e6; x1 <= 1e6; x1++) {
		bool th = false;
		ll tam = c1 - a1 * x1;
		if (b1 == 0) {
			if (tam != 0) continue;
			ll tam2 = c2 - a2 * x1;
			if (b2 != 0) {if (tam2 % b2 == 0) th = 1;}
			else {
				if (tam2 == 0) th = 1;
			}
		}
		else {
			if (tam % b1 == 0) {
				ll y1 = tam / b1;
				if (a2 * x1 + y1 * b2 == c2) th = 1;
			}
		}
		if (th && b1 == 0 && b2 == 0) {
			cout << "INFINITE" << '\n';
			return ;
		}
		if (th) {
			res ++;
					if (res > 2) {
						cout << "INFINITE" << '\n';
						return ;
					}
					else {
						pos = x1;
						if (b1 != 0) pos2 = (c1 - a1 * pos) / b1;
					}
		}
	}
	if (res == 0) cout << "NO SOLUTION" << '\n';
	else cout << pos << " " << pos2 << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
    