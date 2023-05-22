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

const string NAME = "d2set";
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

ll n, k, a[1000003];

bool check[1000003];

int bs(int x) {
	int l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] > x) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}

void sub12() {
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll ans = 0;
	ll cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		int dem = 1;
		int val = a[i];
		while (1) {
			int tam = bs(val * 2);
			if (tam  == 0) break;
			dem ++;
			val *= 2;
			check[tam] = 1;
		}
		if (dem % 2 == 0) {
			ans += dem / 2;
			cnt *= (dem / 2) + 1;
			cnt %= k;
		}
		else ans += dem / 2 + 1;
	}
	cout << ans << " " << cnt << '\n';
}

void sol() {
	cin >> n >> k;
	if (n <= 1e6) sub12();
	//else sub3();	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
