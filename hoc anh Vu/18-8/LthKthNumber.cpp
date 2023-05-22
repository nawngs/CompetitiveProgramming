#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, a[200003], t;

bool check(int x) {
	int l = 1, r = 0, dem = 0, res = 0;
	while (l <= n) {
		while (r < n && dem < k) {
			r ++;
			dem += (a[r] <= x);
		}
		if (dem == k) res += (n - r + 1);
		dem -= (a[l] <= x);
		l ++;
	}
	return (res >= t);
}

signed main() {
	fast;
	cin >> n >> k >> t;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
}
