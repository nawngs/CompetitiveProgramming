#include <bits/stdc++.h>

#define name ""
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
const ll LINF = 1E15;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, q, a[100003], res[100003];

pll b[100003];

ll add(ll x, ll y) {
	x += y;
	if (x > LINF) x = LINF;
	return x;
} 

ll mul(ll a, ll b) {
	if (a == 0 || b == 0) return 0;
	if (a > LINF / b) return LINF;
	return a * b;
}

void sol() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= q; i++) cin >> b[i].fi, b[i].se = i;
	sort(b + 1, b + q + 1);
	ll pos = 0, val = 1, cur = 0;
	for (int i = 1; i <= q; i++) {
		cur = add(cur, mul(b[i].fi - b[i - 1].fi, val));
		while (pos < n && cur > a[pos + 1]) {
			++ pos;
			val = mul(val, 2);
			cur = mul(2, add(cur, -a[pos]));
		}
		res[b[i].se] = pos;
	}
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}