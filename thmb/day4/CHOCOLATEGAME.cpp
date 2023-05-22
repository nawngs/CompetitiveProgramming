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
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, k;

int main() {
	fast;
	cin >> n >> m >> k;
	if (((n * m) - 1 - k) % 2 == 0) {
		cout << 0 << '\n';
		return 0;
	}	
	ll ans = n + m - 2;
	for (int i = 1; i <= k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		ans = ans + max(0, abs(a - c) - 1) + max(0, abs(b - d) - 1);
	}
	cout << ans - k;
}
