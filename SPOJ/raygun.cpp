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
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll f[nmax + 5], dem = 0, cur = 1, calc[nmax + 5];

ll n, m;

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = i;
	for (int i = 2; i * i <= nmax; i++) 
		if (f[i] == i) for (int j = i * i; j <= nmax; j+=i) f[j] = i;
}

int main() {
	fast;
	//fre();
	int t;
	cin >> t;
	sang();
	for (int i = 1; i <= nmax; i++) {
		int x = i;
		bool th = true;
		int cnt = 0;
		while (x > 1) {
			int temp = f[x];
			cnt ++;
			int dem = 0;
			while (x % temp == 0) {
				x /= temp;
				dem ++;
			}
			if (dem > 1) {
				th = false;
				break;
			}
		}
		if (th) calc[i] = cnt;
		else calc[i] = -1;

	}
	for (int test = 1; test <= t; test++) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			cout << "Case " << test << ": " << 0 << '\n';
			continue;
		}
		if (n == 0 || m == 0) {
			cout << "Case " << test << ": " << 1 << '\n';
			continue;
		}
		if (n > m) swap(n, m);
		ll ans = 0;
		for (int i = 1; i <= n; i++) {
			if (calc[i] == -1) continue;
			if (calc[i] % 2 == 1) ans -= (n / i) * (m / i);
			else ans += (n / i) * (m / i);
		}
		cout << "Case " << test << ": " << ans + 2 << '\n';
	}
}
