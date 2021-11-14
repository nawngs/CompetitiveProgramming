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
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[200005], b[200005];

bool check[nmax + 5];

void sang() {
	for (int i = 1; i <= nmax; i++) check[i] = true;
	check[1] = check[0] = false;
	for (int i = 2; i * i <= nmax; i++)
		if (check[i]) for (int j = i * i; j <= nmax; j += i) check[j] = false; 
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	ll ans = 0;
	ll incre = 0, decre = 0, cntin = 0, cntde = 0;
	for (int i = 2; i <= n; i++) {
		ll tam = b[i] - a[i];
		a[i] += tam;
		ans += abs(tam);
		if (check[i]) {
			if (tam > 0) {
				cntin ++;
				incre += abs(tam);
			}
			if (tam < 0) {
				cntde ++;
				decre += abs(tam);
			}
		}
		for (int j = i * 2; j <= n; j += i) a[j] += tam;
	}
	ll q;
	cin >> q;
	while (q --) {
		ll x;
		cin >> x;
		ll tam = abs(x - a[1]);
		if (x > a[1]) cout << tam + ans + tam * cntde + incre - tam * cntin << '\n';
		if (x == a[1]) cout << ans << '\n';
		if (x < a[1]) cout << ans + tam + tam * cntin + decre - tam * cntde << '\n';
	}
}

int main() {
	fast;
	sang();
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
