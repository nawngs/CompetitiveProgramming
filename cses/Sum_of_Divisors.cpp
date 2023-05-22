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

ll n;

ll calc(ll l, ll r) {
	if (l > r) return 0;
	ll tam1, tam2;
	if ((r + l) % 2 == 0) {
		tam1 = (r + l) / 2;
		tam2 = (r - l + 1);
	}
	else {
		tam1 = r + l;
		tam2 = (r - l + 1) / 2;
	}
	return ((tam1 % MOD) * (tam2 % MOD)) % MOD;;
}

void sol() {
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		ans = (ans + i * ((n / i) - i + 1)) % MOD;
		ans = (ans + calc(i + 1, n / i)) % MOD;
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
