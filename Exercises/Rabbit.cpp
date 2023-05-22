#include <bits/stdc++.h>

#define name "rabbit"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, k, a[200003], d[200003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	a[1] = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i + 1];
		a[i + 1] -= 1ll * i * k;
	}
	n ++;
	d[0] = -LINF;
	for (int i = 1; i <= n; i++)
		d[i] = LINF;
	for (int i = n; i >= 1; i--) {
		int l = 0, r = n, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			if (d[mid] <= a[i]) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (i == 1) {
			cout << n - ans - 1 << '\n';
			return 0;
		}
		d[ans + 1] = min(d[ans + 1], a[i]);
	}
}