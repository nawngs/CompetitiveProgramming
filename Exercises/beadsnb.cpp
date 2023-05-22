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

ll n, a[100003], f[100003], g[100003], temp[100003];

void lis() {
	for (int i = 1; i <= n; i++) temp[i] = INF;
	temp[0] = 0;
	for (int i = n; i >= 1; i--) {
		int l = 0, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (temp[mid] < a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		f[i] = ans + 1;
		temp[ans + 1] = min(temp[ans + 1], a[i]);
	}
}

void lds() {
	for (int i = 1; i <= n; i++) temp[i] = 0;
	temp[0] = INF;
	for (int i = n; i >= 1; i--) {
		int l = 0, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (temp[mid] > a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		g[i] = ans + 1;
		temp[ans + 1] = max(temp[ans + 1], a[i]);
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	lis();
	lds();
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, f[i] + g[i] - 1);
	cout << ans;
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
