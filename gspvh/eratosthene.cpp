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

const string NAME = "eratosthene";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll l, r;

bool Prime[5000003];

int main() {
	fast;
	fre();
	cin >> l >> r;
	memset(Prime, 1, sizeof(Prime));
	for (ll i = 2; i * i <= r; i++) 
		for (ll j = max(i * i, (l + i - 1) / i * i); j <= r; j+=i) Prime[j - l] = false;
	if (1 >= l) 
		Prime[1 - l] = 0;
	int res = 0;
	for (ll i = l; i <= r; i++)
		res += Prime[i - l];
	cout << res;
}
