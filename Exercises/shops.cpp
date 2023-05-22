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

const string NAME = "shops";
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

ll n, s, a[500004], val[500003], it[3000003], dem = 1, res = 0, pos = -1;

void roi_rac() {
	vector < pll > f;
	for (int i = 1; i <= n; i++) f.push_back({a[i], i});
	sort(f.begin(), f.end());
	for (int i = 0; i < f.size(); i++) {
		dem += (i != 0 && f[i].fi != f[i - 1].fi);
		val[dem] = a[f[i].se];
		a[f[i].se] = dem;
	}
}

void update(ll node, ll l, ll r, ll pos, ll gt) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = min(it[node], gt);
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, gt);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, gt);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return INF;
	if (u <= l && r <= v) return it[node];
	return min(query(node * 2, l, (l + r) / 2, u, v), query(node * 2 + 1, (l + r) / 2 + 1, r, u, v));
}

ll bs(ll gt) {
	ll l = 1, r = dem, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (val[mid] >= gt) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	//if (ans != -1 && gt > val[ans]) cout << 1 << '\n';
	return ans;
}

void get_ans(ll l, ll r) {
	if (r - l > res) {
		res = r - l;
		pos = l;
	}
	else if (r - l == res) pos = min(pos, l);
}

void sol() {
	cin >> n >> s;
	n ++;
	for (int i = 2; i <= n; i++) {
		ll x;
		cin >> x;
		a[i] = a[i - 1] + x;
	}
	roi_rac();
	for (int i = 1; i <= 6 * dem; i++) it[i] = INF;
	for (int i = 1; i <= n; i++) {
		ll tam = query(1, 1, dem, a[i], dem);
		if (tam < i) get_ans(tam, i);
		ll gt = bs(val[a[i]] - s);
		if (gt != -1) {
			tam = query(1, 1, dem, gt, a[i]);
			if (tam < i) get_ans(tam, i);
		}
		update(1, 1, dem, a[i], i);
	}
	cout << res << " " << pos << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
