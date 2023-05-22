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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[100003], f[100003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = -INF;
	}
	f[0] = INF;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (f[mid] > a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		res = max(res, ans + 1);
		f[ans + 1] = max(f[ans + 1], a[i]);
	}
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
