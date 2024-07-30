#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "vomario";
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

struct line {
	ll a, b;
};

struct Data {
	ll x, w, e;
};

line it[600003];

ll n, val_pos[100003], dem, dp[100003];

Data a[100003];

vector < pll > f;

void roi_rac() {
	f.clear();
	for (int i = 0; i <= n; i++) f.push_back(make_pair(a[i].x, i));
	sort(f.begin(), f.end());
	dem = 1;
	for (int i = 0; i < f.size(); i++) {
		dem += (i != 0 && f[i].fi != f[i - 1].fi);
		val_pos[dem] = a[f[i].se].x;
		a[f[i].se].x = dem;
	}
 }

ll get(line d, ll x) {
	return d.a * val_pos[x] + d.b;
}

ll query(ll node, ll l, ll r, ll pos) {
	if (pos < l || pos > r) return -INF;
	ll res = get(it[node], pos);
	if (l == r) return res;
	res = max(res, query(node * 2, l, (l + r) / 2, pos));
	res = max(res, query(node * 2 + 1, (l + r) / 2 + 1, r, pos));
	return res;
}

void update(ll node, ll l, ll r, ll u, ll v, line val) {
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		int m = (l + r) / 2;
		bool mid = get(val, m) > get(it[node], m);
		bool lef = get(val, l) > get(it[node], l);
		if (mid) swap(it[node], val);
		if (l == r) return ;
		if (lef != mid) update(node * 2, l, m, u, v, val);
		else update(node * 2 + 1, m + 1, r, u, v, val);
	}
	else if (l != r) {
		update(node * 2, l, (l + r) / 2, u, v, val);
		update(node * 2 + 1, (l + r) / 2 + 1, r, u, v, val);
	}
}

ll bs1(ll x) {
	int l = 1, r = dem, mid, ans = 1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (val_pos[mid] >= x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
 }

 ll bs2(ll x) {
	int l = 1, r = dem, mid, ans = dem;
	while (l <= r) {
		mid = (l + r) / 2;
		if (val_pos[mid] <= x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
 }

void sol() {
	cin >> n;
	a[0].x = a[0].w = a[0].e = 0;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].w >> a[i].e;
	roi_rac();
	line tem;
	tem.a = tem.b = 0;
	update(1, 1, dem, 1, dem, tem);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = query(1, 1, dem, a[i].x) + a[i].e;
		ans = max(ans, dp[i]);
		ll tam = (a[i].w == 0 ? INF : dp[i] / a[i].w);
		ll posl = bs1(val_pos[a[i].x] - tam);
		ll posr = bs2(val_pos[a[i].x] + tam);
		line tem;
		tem.a = a[i].w;
		tem.b = dp[i] - a[i].w * val_pos[a[i].x];
		update(1, 1, dem, posl, a[i].x, tem);
		tem.a = -a[i].w;
		tem.b = dp[i] + a[i].w * val_pos[a[i].x];
		update(1, 1, dem, a[i].x, posr, tem);
	}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
