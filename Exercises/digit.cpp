#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "digit";
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

ull a, b, k;

ull nhan(ull A, ull B, ull M){
    if (B == 0)
        return 0;

    ull T = nhan(A, B / 2, M) % M;

    if (B & 1)
        return ((T + T) % M + A % M) % M;
    else
        return (T + T) % M;
}

ull mu(ull a, ull b, ull k) {
	if (b == 0) return 1;
	ull x = mu(a, b / 2, k);
	x = nhan(x, x, k);
	if (b % 2 == 1) x = nhan(x, a, k);
	return x;
}

void sol() {
	cin >> a >> b >> k;
	a %= b;
	a = nhan(a, mu(10, k - 1, b), b);
	a *= 10;
	a/= b;
	cout << a % 10 << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
