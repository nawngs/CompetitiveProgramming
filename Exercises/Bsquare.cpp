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

const string NAME = "Bsquare";
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

int n, f[nmax + 5], cnt[nmax + 5];

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = i;

	for (int i = 2; i * i <= nmax; i++) 
		if (f[i] == i) for (int j = i * 2; j <= nmax; j += i) f[j] = i;
}

int main() {
	fast;
	//fre();
	sang();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll tam = i;
		ll pre = -1, dem = 0;
		ll res = 1;
		while (tam > 1) {
			if (f[tam] == pre) dem ++;
			else {
				if (dem % 2 == 1) res *= pre;
				dem = 1;
			}
			pre = f[tam];
			tam /= f[tam];
		}
		if (dem % 2 == 1) res *= pre;
		cnt[res] ++;
	}
	ll ans = 0;
	for (int i = 1; i <= nmax; i++) ans += cnt[i] * (cnt[i] - 1) / 2;
	cout << ans;
}
