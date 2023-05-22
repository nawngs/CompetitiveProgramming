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
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, p, frac[2 * nmax + 3];

ll mu(ll a, ll b, ll p) {
	if (b == 0) return (1 % p);
	ll x = mu(a, b / 2, p);
	x = (x * x) % p;
	if (b % 2 == 1) x = (x * a) % p;
	return x;
}

ll Ckn(ll n, ll k, ll p) {
	if (k > n) return 0;
	return (frac[n] * mu((frac[k] * frac[n - k]) % p, p - 2, p)) % p;
}

int calculateUsingLT(int n, int r, int p) {
	if (r==0) return 1;
	int ni = n%p, ri = r%p;
	int res1 = calculateUsingLT(n/p, r/p, p);
	int res2 = Ckn(ni, ri, p);
	int res = (res1 * res2) % p;
	return res;
}


void sol() {
	cin >> n >> p;
	frac[0] = 1;
	for (int i = 1; i <= 2 * n; i++) 
		frac[i] = (frac[i - 1] * i) % p;
	ll res = 0;
	if (n % 2 == 0) 
		res = ((res + calculateUsingLT(n, n / 2, p) - 1 - n / 2) % p + p) % p;
	ll temp = 1, pre = 1;
	for (int i = 1; i <= n; i++) {
		ll newt = (temp + pre) % p;
		pre = temp;
		temp = newt;
	}
	cout << (temp + res) % p << '\n';
}

int main() {
	fast;
	//fre();
	
	int t = 1;
	cin >> t;
	while (t --) sol();
}
