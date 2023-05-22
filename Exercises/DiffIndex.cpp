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

const string NAME = "DiffIndex";
const string NAME2 = "TEST";
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

int n, a[200006];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= i;
	}
	sort(a + 1, a + n + 1);
	a[n + 1] = -1e9;
	ll ans = 0, dem = 1;
	for (int i = 2; i <= n + 1; i++) {
		if (a[i] == a[i - 1]) dem ++;
		else {
			ans += dem * (dem - 1) / 2;
			dem = 1;
		}
	}
	cout << ans << '\n';
}

int main() {
	fast;
		fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
