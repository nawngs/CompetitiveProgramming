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

ll x, d;

bool check(ll x) {
	for (int i = 2; i  * i <= x; i++) if (x % i == 0) return false;
	return true;
}

void sol() {
	cin >> x >> d;
	if (x % (d * d) != 0) {
		cout << "NO" << '\n';
		return ;
	}
	int dem = 0;
	while (x > d && x % d == 0) {
		x /= d;
		dem ++;
	}
	if (check(x)) cout << "NO" << '\n';
	else cout << "YES" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
