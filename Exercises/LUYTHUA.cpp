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

const string NAME = "LUYTHUA";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll a, b;

ll getans(ll a, ll b) {
	//cout << a << " " << b << '\n';
	if (b == 0) return 1;
	ll x = getans(a, b / 2);
	x = ((x % MOD) * (x % MOD)) % MOD;
	if (b % 2 == 1) x = ((x % MOD) * (a % MOD)) % MOD;
	return x;
}

bool check() {
	if (a == 1) return false;
	ll dem = 0;
	ll tam = 1;
	while (tam <= MOD) {
		dem ++;
		tam *= a;
	}
	dem --;
	return (dem <= b);
}

void sol() {
	cin >> a >> b;
	ll ans = getans(a, b);
	if (check()) {
		vector < ll > res;
		res.clear();	
		while (ans > 0) {
			res.push_back(ans % 10);
			ans /= 10;
		}
		while (res.size() < 9) res.push_back(0);
		reverse(res.begin(), res.end());
		for (auto x : res) cout << x;
	}
	else cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
