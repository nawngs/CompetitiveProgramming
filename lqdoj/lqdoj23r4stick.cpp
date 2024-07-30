#include <bits/stdc++.h>

#define name "stick"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 1E6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[NMAX + 3];

ll get3(ll x) {
	return x * (x - 1) * (x - 2) / 6;
}

ll get2(ll x) {
	return x * (x - 1) / 2;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll dem = 1, res = 0;
	for (ll i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) dem ++;
		else {
			res += get3(dem);
			ll temp = get2(dem);
			res += temp * (i - dem - 1);
			int l = i, r = n, mid, ans = i - 1;
			while (l <= r) {
				mid = (l + r) / 2;
				if (a[mid] < 2 * a[i - 1]) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			res += temp * (ans - i + 1);
			dem = 1;
		}
	}
	res += get3(dem);
	res += get2(dem) * (n - dem);
	cout << res;
}