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

const string NAME = "";
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

int n, dem = 0, it[600003], pre_pos, last[100003];

pair < pii, int > a[100003];

stack < int > not_used[100003];

void roi_rac() {
	vector < pair < int, int > > f;
	for (int i = 1; i <= n; i++) f.push_back({a[i].fi.se, i});

	sort(f.begin(), f.end());
	for (int i = 0; i < f.size(); i++) {
		dem += (i == 0 || f[i].fi != f[i - 1].fi);
		a[f[i].se].fi.se = dem;
	}
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = val;
		return ;
	}
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	return query(node * 2, l, (l + r) / 2, u, v) + query(node * 2 + 1, (l + r) / 2 + 1, r, u, v);
}

int bs(int val) {
	int l = val + 1, r = dem, mid, ans = -1;
	pre_pos = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		int tam = query(1, 1, n, val + 1, mid);
		if (tam > 0) {
			pre_pos = tam;
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi.fi >> a[i].fi.se;
		a[i].se = i;
	} 	
	roi_rac();
	sort(a + 1, a + n + 1, [](pair < pii, int > &x, pair < pii, int > &y) {
		return (x.fi.fi > y.fi.fi) || (x.fi.fi == y.fi.fi && x.fi.se < y.fi.se);
	});
	int cnt = 1;
	update(1, 1, n, a[1].fi.se, 1);
	last[1] = 0;
	for (int i = 2; i <= n; i++) {
		int temp = bs(a[i].fi.se);
		if (temp == -1) {
			cnt ++;
			last[i] = 0;
			if (query(1, 1, n, a[i].fi.se, a[i].fi.se)) not_used[a[i].fi.se].push(i);
			else update(1, 1, n, a[i].fi.se, i);
		}
		else {
			last[i] = pre_pos;
			//cout << i << " " << last[i] << '\n';
			if (not_used[temp].size()) {
				update(1, 1, n, temp, not_used[temp].top());
				not_used[temp].pop();
			}
			else update(1, 1, n, temp, 0);
			update(1, 1, n, a[i].fi.se, i);
		}
	}
	cout << cnt << '\n';
	for (int i = n; i >= 1; i--) {
		if (last[i] != -1) {
			vector < int > res;
			res.clear();
			int pos = i;
			while (pos != 0) {
				res.push_back(a[pos].se);
				int pre = last[pos];
				last[pos] = -1;
				pos = pre;
			}
			reverse(res.begin(), res.end());
			cout << res.size() << " ";
			for (auto x : res) cout << x << " ";
			cout << '\n';
		}
	}
}	

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
