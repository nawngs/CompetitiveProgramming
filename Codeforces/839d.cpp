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
const ll nmax = 1000000;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[200003], val[nmax + 3], pw[nmax + 3], cnt[nmax + 3];

bool IsPrime[nmax + 3];

void sieve() {
	memset(IsPrime, 1, sizeof(IsPrime));
	IsPrime[0] = IsPrime[1] = false;
	for (int i = 2; i * i <= nmax; i++)
		if (IsPrime[i])
			for (int j = i * i; j <= nmax; j+=i) 
				IsPrime[j] = false;
}

ll calc(ll x) {
	return (x * pw[x - 1]) % MOD;
}

int main() {
	fast;
	//fre();
	sieve();
	pw[0] = 1;
	for (int i = 1; i <= nmax; i++) {
		val[i] = 1;
		pw[i] = (pw[i - 1] * 2) % MOD;
	}
	for (int i = 2; i <= nmax; i++) {
		if (IsPrime[i])
			for (int j = i; j <= nmax; j+=i) {
				if (j % (i * i) == 0) val[j] = 0;
				else val[j] *= -1;
			}
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	for (int i = 1; i <= nmax; i++)
		for (int j = i * 2; j <= nmax; j+=i) 
			cnt[i] += cnt[j];
	ll res = 0;
	for (int i = 2; i <= nmax; i++) {
		ll total = 0;
		for (int j = i; j <= nmax; j+=i)
			total = (total + val[j / i] * calc(cnt[j])) % MOD;
		res = (res + i * total) % MOD;
	}
	cout << (res + MOD) % MOD;
}
