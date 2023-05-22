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
const ll nmax = 1e4;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll cnt_p[nmax + 3], product[nmax + 3], cnt[nmax + 3], n, a[nmax + 3];

bool prime[nmax + 3];

void init() {
	for (int i = 1; i <= nmax; i++) product[i] = 1;
	memset(prime, 1, sizeof(prime));
	for (int i = 2; i <= nmax; i++) {
		if (prime[i]) {
			for (int j = i; j <= nmax; j+=i) {
				product[j] *= i;
				cnt_p[j] ++;
				if (j != i) prime[j] = false;
			}
		}
	}
}

ll calc(ll x) {
	return x * (x - 1) * (x - 2) * (x - 3) / 24;
}

void sol() {
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				cnt[j] ++;
				if (j * j != a[i]) cnt[a[i] / j] ++;
			}
		}
	}
	ll res = 0;
	for (int i = 2; i <= nmax; i++) {
		if (product[i] != i) continue;
		//cout << i << " " << cnt[i] << '\n';
		if (cnt_p[i] % 2) res += calc(cnt[i]);
		else res -= calc(cnt[i]);
	}
	cout << calc(n) - res << '\n';
}

int main() {
	fast;
	init();
	while (cin >> n) sol();
}
