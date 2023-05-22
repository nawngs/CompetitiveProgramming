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
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[20];

ll calc(ll l, ll r, ll num1, ll num2) {
	if (l == r - 1) 
		return 0;
	ll temp = LINF;
	for (int i = l + 1; i < r; i++)
		temp = min(temp, calc(l, i, num1, num1 + num2) + calc(i, r, num1 + num2, num2) + a[i] * (num1 + num2));
	return temp;
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << a[1] + a[n] + calc(1, n, 1, 1);
}
