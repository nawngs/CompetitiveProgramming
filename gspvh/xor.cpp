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

const string NAME = "xor";
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

ll a, n;

bool check(ll x, ll i) {
	ll l = (x + n - 1) / n;
	ll r = (x + (1ll << i) - 1) / n;
	return (r - l) >= 0;
}

int main() {
	fast;
	//fre();
	cin >> a >> n;
	ll cur = 0, res = 0;
	for (int i = 60; i >= 0; i--) {
		ll val = a & (1ll << i);
		ll temp = val ^ 0;
		if (check(cur + temp, i)) cur += temp;
		else {
			res ^= (1ll << i);
			temp = val ^ (1ll << i);
			cur += temp;
		}
	}
	cout << res;
}
