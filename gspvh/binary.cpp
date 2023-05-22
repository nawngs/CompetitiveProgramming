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

const string NAME = "binary";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 4e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, mu[62];

int main() {
	fast;
	fre();
	cin >> n >> k;
	ll ans = INF;
	ll cur = n;
	mu[0] = 1;
	for (int i = 1; i < 62; i++) mu[i] = mu[i - 1] * 2;
	for (int i = 0; i < k - 1; i++) cur = cur | mu[i];
	for (int i = k - 1; i < 62; i++) {
		cur = cur | mu[i];
		if (i != k - 1) cur -= mu[i - k];
		if (n > cur && n - cur < mu[i - k + 1]) {
			cout << n;
			return 0;
		}
		ans = min(ans, cur);
	}
	cout << ans;
}