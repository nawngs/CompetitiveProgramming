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

ll n, a[300003];

ll odd, even;

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	odd = 0;
	even = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[n]) break;
		if ((a[n] - a[i]) % 2 == 1) odd += a[n] - a[i];
		else even += a[n] - a[i];
	}
	ll last_even = even;
	ll last_odd = odd * 2 - 1;
	if (abs(last_odd - last_even) == 1) {
		cout << max(last_odd, last_even) << '\n';
		return ;
	}
	if (last_odd < last_even) {
		ll ans = last_odd;
		last_even -= last_odd / 2;
		last_even = (last_even / 3) * 2 + (last_even % 3 != 0);
		cout << ans + last_even << '\n';
		return ;
	}
	ll ans = last_even;
	last_odd -= last_even;
	last_odd = (last_odd / 3) * 2 + (last_odd % 3 == 1) + 2 * (last_odd % 3 == 2);
	cout << ans + last_odd << '\n';

}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
