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

const string NAME = "baseb";
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

ll c, d, b, m;

map < int, vector < ll > > vec;

int main() {
	fast;
	//fre();
	cin >> c >> d >> b >> m;
	ll X = 1;
	while (1) {
		ll val = c * X + d;
		ll temp = 0;
		while (val > 0) {
			 temp += val % b;
			 val /= b;
		}
		vec[temp].push_back(X);
		if (vec[temp].size() == m) {
			for (auto x : vec[temp]) cout << x << " ";
			return 0;
		}
		X += b - 1;
	}	
}
