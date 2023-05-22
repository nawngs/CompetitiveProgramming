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

const string NAME = "";
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

ll a, b;

bool check (ll x) {
	vector < int > digit;
	digit.clear();
	while (x > 0) {
		digit.push_back(x % 10);
		x /= 10;
	} 
	for (int i = 1; i < digit.size(); i++) if (digit[i] == digit[i - 1]) return false;
	for (int i = 2; i < digit.size(); i++) if (digit[i] == digit[i - 2]) return false;
	return true;

}

ll calc(ll x) {
	ll dem = 0;
	for (int i = 1; i <= x; i++) dem += check(i);
	return dem;
}

void sol() {
	cin >> a >> b;
	cout << calc(b);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
