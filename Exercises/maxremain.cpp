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

const string NAME = "maxremain";
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

int n, a[200003];

int bs(int x) {
	int l = 1, r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] <= x) {
			ans = a[mid];
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n <= 1000) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, a[j] % a[i]);
			}
		}
		cout << ans << '\n';
	}
	else {
		int ans = 0;
		a[0] = -1;
		for (int i = 1; i <= n; i++) {
			if (a[i] == a[i - 1]) continue;
			for (int k = 2; a[i] * (k - 1) <= a[n]; k++) {
				int tam = bs(a[i] * k - 1);
				if (tam > a[i] * (k - 1)) ans = max(ans, tam - a[i] * (k - 1));
	 		}
		}
		cout << ans << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
