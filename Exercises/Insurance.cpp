#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "Insurance";
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

ll n;
ll a[200005], s[200005];

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	ld ans = INF;
	for (int i = 1; i <= n; i++) {
		ld tam = (ld) a[i] / 2;
		ld res = tam * i;
		ld temp = (ld) s[n] - (ld) s[i];
		res = res + temp - tam * (n - i);
		ans = min(ans, res);
	}
	cout << fixed << setprecision(1) << ans << '\n';
}
