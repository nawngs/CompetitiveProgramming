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

const ll num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const ll cnt[10] = {1, 5, 1, 2, 2, 3, 1, 2, 0, 0};
const ll dem[10] = {0, 1, 0, 0, 0, 0, 0, 2, 0, 0};

ll v, n;

void sol() {
	cin >> v >> n;
	if (v == 1) {
		ll ans = 0;
		while (n > 0) {
			ans += num[n % 10];
			n /= 10;
		}
		cout << ans;
	}
	else {
		ll ans = 1;
		ll s = 0;
		ll s2 = 1;
		
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
