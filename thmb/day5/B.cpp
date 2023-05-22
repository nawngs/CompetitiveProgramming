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

int n, a[300003], z[300003];

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	z[1] = 0;
	int l = 0, r = 0;
	for (int i = 2; i <= n; i++) {
		int &x = z[i];
		if (i <= r) x = min(r - i + 1, z[i - l + 1]);
		while (i + x <= n && a[x + 1] == a[i + x]) {
			x ++;
			l = i;
			r = i + x - 1;
		}
		//cout << i << " " << z[i] << '\n';
	}
	for (int i = 1; i < n; i++) {
		if (z[i + 1] == n - i) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << n;
}
