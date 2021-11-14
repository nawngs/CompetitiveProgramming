//#pragma GCC optimize ("O3")
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

int n;

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x);
	if (b % 2 == 1) x = (x * a);
	return x;
}

void sol() {
	cin >> n;
	ll num1, num0;
	num1 = num0 = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		num0 += (x == 0);
		num1 += (x == 1);
	}
	cout << num1 * mu(2, num0) << '\n';	
}

int main() {
	fast;
	//fre();
	int t;
	cin >> t;
	while (t --) sol();
}
