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

ll x, y;


ll calc(ll wat) {
	ll money = 0;
	if (wat > 0) money += min(wat, 1ll * 100) * 200;
	if (wat > 100) money += (min(wat, 1ll * 10000) - 100) * 300;
	if (wat > 10000) money += (min(wat, 1ll * 1000000) - 10000) * 500;
	if (wat > 1000000) money += (wat - 1000000) * 700;
	return money;
} 

void sol() {
	cin >> x >> y;
	ll l = 1, r = 1e10, mid, sum_wat;
	while (l <= r) {
		mid = (l + r) / 2;
		ll tam = calc(mid);
		if (tam == x) {
			sum_wat = mid;
			break;
		}
		if (tam > x) r = mid - 1;
		if (tam < x) l = mid + 1;
	}
	l = 0; r = sum_wat / 2;
	while (l <= r) {
		mid = (l + r) / 2;
		ll nam = calc(mid);
		ll viet = calc(sum_wat - mid);
		if (viet - nam == y) {
			cout << nam;
			return ;
		}
		if (viet - nam < y) r = mid - 1;
		if (viet - nam > y) l = mid + 1;
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
