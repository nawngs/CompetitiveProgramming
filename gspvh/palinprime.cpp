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

const string NAME = "palinprime";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

vector < ll > prime;

bool check[nmax + 5];

void sang() {
	memset(check, 1, sizeof(check));
	check[1] = check[0] = false;
	for (int i = 2; i * i <= nmax; i++)
		if (check[i]) for (int j = i * i; j <= nmax; j+=i) check[j] = false;
	for (int i = 1; i <= nmax; i++) if (check[i]) prime.push_back(i); 
}

bool kt(ll x) {
	vector < ll > digit;
	digit.clear();
	while (x > 0) {
		digit.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0; i < digit.size(); i++) if (digit[i] != digit[digit.size() - 1 - i]) return false;
	return true;
}

void sol() {
	sang();
	// cout << prime.size() << '\n';;
	ll l, r;
	cin >> l >> r;
	ll res = 0;
	for (auto x : prime) {
		if (x > r) break;
		if (x < l) continue;
		res += (kt(x) ? 1ll * x : 0);
	}
	cout << res;
 }

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
