#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const ll LG = 61;

ll n, k, c[NMAX + 3], cnt[LG + 3];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> c[i];
	vector < ll > v;
	if (n <= 1000) {
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) v.pb(c[i] ^ c[j]);
		sort(v.begin(), v.end());
		cout << v[k - 1] << '\n';
		return 0;
	}
	v.clear();
	v.pb(0);
	for (int i = 0; i <= LG; i++)
	for (int j = i + 1; j <= LG; j++) v.pb((1ll << i) + (1ll << j));
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= LG; j++) if (c[i] >> j & 1) cnt[j] ++;
	ll dem = 0;
	for (auto x : v) {
		if (x == 0) for (int j = 0; j <= LG; j++) dem += (cnt[j] * (cnt[j] - 1)) / 2;
		else {
			int pre = -1;
			for (int j = 0; j <= LG; j++) if (x >> j & 1) {
				if (pre == -1) pre = j;
				else dem += cnt[pre] * cnt[j];
			}
		}
		if (dem >= k) {
			cout << x << '\n';
			return 0;
		}
	}
}