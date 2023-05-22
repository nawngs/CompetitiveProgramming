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
const ll nmax = 5e6;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, f[nmax + 5], cnt[nmax + 5];

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = i;

	for (int i = 2; i * i <= nmax; i++) 
		if (f[i] == i) for (int j = i * 2; j <= nmax; j += i) f[j] = i;
}

void sol() {
	cin >> n;
	sang();
	for (int i = 1; i <= n; i++) {
		ll tam = i, s = 1, pre = 1, dem = 0;
		while (tam > 1) {
			if (f[tam] == pre) dem ++;
			else {
				if (dem % 2 == 1) s *= pre;
				dem = 1;
			}
			pre = f[tam];
			tam /= f[tam];
		}
		if (dem % 2 == 1) s *= pre;
		cnt[s] ++;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = ans + (cnt[i]) * (cnt[i] - 1) * (cnt[i] - 2) / 6;
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
