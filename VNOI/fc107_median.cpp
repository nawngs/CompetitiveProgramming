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

const string NAME = "";
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

ll n, a[200003], val[200003], it[1200003];

vector < pll > temp;

void roi_rac() {
	temp.clear();
	for (int i = 1; i <= n; i++) temp.push_back({a[i], i});
	sort(temp.begin(), temp.end());
	int dem = 1;
	for (int i = 0; i < temp.size(); i++) {
		if (i != 0) dem += temp[i].fi != temp[i - 1].fi;
		val[dem] = a[temp[i].se];
		a[temp[i].se] = dem;
	}
}

void update(ll node, ll l, ll r, ll pos, ll val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] += val;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
} 

ll query(ll node, ll l, ll r, ll u, ll v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(node * 2, l, (l + r) / 2, u, v) + query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
}

ll bs(ll val) {
	ll l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (query(1, 1, n, 1, mid) >= val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	roi_rac();
	for (int i = 1; i <= n; i++) update(1, 1, n, a[i], 1);
	for (int i = 1; i <= n; i++) {
		update(1, 1, n, a[i], -1);
		cout << val[bs(n / 2)] << '\n';
		update(1, 1, n, a[i], 1);
	}
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
