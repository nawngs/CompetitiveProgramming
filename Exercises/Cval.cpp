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

const string NAME = "Cval";
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

int n, m, it[800003], a[200003], last[200003], pre[200003];

vector < int > roi_rac, pos[200003];

void update(int node, int l, int r, int pos, int val) {
	if  (pos < l || pos > r) return ;
	it[node] = max(it[node], val);
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return -1;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= 4 * n; i++) it[i] = -1;
	roi_rac.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = -1;
		roi_rac.push_back(a[i]);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 0; i < roi_rac.size(); i++) pos[i].clear();
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(roi_rac.begin(), roi_rac.end(), a[i]) - roi_rac.begin();
		pos[a[i]].push_back(i);
		last[a[i]] = -1;
	} 
	for (int i = 1; i <= m; i++) {
		int l, r;
		cin >> l >> r;
		update(1, 1, n, l, r);
	}
	int r = 0;
	for (int i = 1; i <= n; i++) {
		if (last[a[i]] != -1 && query(1, 1, n, 1, last[a[i]]) >= i) r = max(r, last[a[i]] + 1);
		pre[i] = last[a[i]];
		last[a[i]] = i;
	}
	if (r == 0) {
		cout << 0 << '\n';
		return ;
	}
	int res = r - 1;
	for (int i = 1; i <= n; i++) {
		if (pre[i] != -1 && query(1, 1, n, 1, pre[i]) >= i) break;
		int far = query(1, 1, n, 1, i);
		if (far != -1) {
			if (pos[a[i]].size()) {
				if (pos[a[i]].back() <= far) r = max(r, pos[a[i]].back() + 1);
				else {
					int id = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), far) - pos[a[i]].begin();
					id --;
					if (id != -1) r = max(r, pos[a[i]][id] + 1);
				}
			}
		}
		res = min(res, r - i - 1); 
	}
	cout << res << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
