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

const string NAME = "";
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll get_random(ll l, ll r) {
	return l + (rng() % (r - l + 1));
}

void sol() {
	
}

int main() {
	fast;
	//fre();
	int n = get_random(1, 20), k = get_random(10, 20);
	cout << n << " " << k << '\n';
	while (n --)
		cout << get_random(1, 15) << ' ';
}
