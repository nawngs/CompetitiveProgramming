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
const ll nmax = 1e6;
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, f[nmax + 3];

ll s[nmax + 3];

ll cnt[nmax + 3];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll calc(ll up, ll down) {
	return (up * mu(down, MOD - 2)) % MOD;
}

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		s[x] = (s[x] + x * cnt[x]) % MOD;
		cnt[x] = (cnt[x] + x) % MOD;
	}
	for (int i = 1; i <= nmax; i++) 
		for (int j = i * 2; j <= nmax; j+=i) {
			s[i] = (s[i] + s[j] + cnt[i] * cnt[j]) % MOD;
			cnt[i] += cnt[j];
			cnt[i] %= MOD;
		}
	ll res = 0;
	for (int i = nmax; i >= 1; i--) {
		//if (s[i] != 0) cout << i << " " << s[i] << '\n'; 
		for (int j = i * 2; j <= nmax; j+=i) 
			s[i] = (s[i] - s[j] + MOD) % MOD;
		//if (s[i] != 0) cout << i << " " << s[i] << '\n';
		res = (res + calc(s[i], i)) % MOD;
	}
	cout << res << '\n';
}
