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
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, s, d, a[100003];

ll res = 0;

pair < ll, int > it[400003];

vector < int > roi_rac;

bool maximize(ll &x, ll y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node].fi += 1ll * val * 1ll * roi_rac[pos]; it[node].se += val * 1;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val); update(node * 2 + 1, mid + 1, r, pos, val);
}

ll walk(int node, int l, int r, int val) {
	if (val >= it[node].se) return it[node].fi;
	if (l == r) 
		return min(1ll * val, 1ll * it[node].se) * 1ll * roi_rac[l];
	int mid = (l + r) / 2;
	if (val <= it[node * 2 + 1].se) return walk(node * 2 + 1, mid + 1, r, val);
	else return it[node * 2 + 1].fi + walk(node * 2, l, mid, val - it[node * 2 + 1].se);
}

void calc(int l, int r, int optl, int optr) {
	if (l > r) return ;
	int mid = (l + r) / 2;
	ll val = 0;
	int opt = optr, choose;
	for (int i = mid + 1; i <= r; i++) update(1, 0, n, a[i], -1);
	for (int k = optr; k >= optl; k--) {
		if (k < s) update(1, 0, n, a[k], 1);
		choose = d - 2 * (s - k) - (mid - s);
		if (choose <= 0) break;
		if (maximize(val, walk(1, 0, n, choose))) opt = k;
	}
	res = max(res, val);
	for (int k = opt; k >= optl; k--) {
		if (k < s) update(1, 0, n, a[k], -1);
		choose = d - 2 * (s - k) - (mid - s);
		if (choose <= 0) break;
	}
	update(1, 0, n, a[mid], -1);
	calc(l, mid - 1, optl, opt);
	for (int k = optr; k > opt; k--) if( k < s) update(1, 0, n, a[k], -1);
	for (int i = mid; i <= r; i++)
		update(1, 0, n, a[i], 1);
	calc(mid + 1, r, opt, optr);
}

 int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> s >> d; s++;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		roi_rac.push_back(a[i]);
	}
	sort(roi_rac.begin(), roi_rac.end()); roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= n; i++) a[i] = lower_bound(roi_rac.begin(), roi_rac.end(), a[i]) - roi_rac.begin();
	for (int i = s; i <= n; i++) update(1, 0, n, a[i], 1);
	calc(s, n, 1, s);
	for (int i = s; i <= n; i++) update(1, 0, n, a[i], -1);
	reverse(a + 1, a + n + 1);
	s = n - s + 1;
	for (int i = s; i <= n; i++) update(1, 0, n, a[i], 1);
	calc(s, n, 1, s);
	for (int i = s; i <= n; i++) update(1, 0, n, a[i], -1);
	cout << res;
}