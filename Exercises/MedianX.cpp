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

const string NAME = "MedianX";
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

int n, x, a[100003];

void sol() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int dem = 0, dem2 = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < x) dem ++;
		if (a[i] == x) dem2 ++;
	}
	if (a[(1 + n) / 2] == x) {
		cout << 0 << '\n';
		return ;
	}
	if (dem + dem2 < (n + 1) / 2) {
		while (dem + dem2 < (n + 1) / 2) {
			dem2 ++;
			ans ++;
			n ++;
		}
		cout << ans;
	}
	else {
		while (dem >= (n + 1) / 2) {
			ans ++;
			n ++;
		}
		cout << ans;
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
