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

int n, k, a[100003], it1[400003], it2[400003], s[100003];

vector < int > roi_rac;

void update(int node, int l, int r, int pos, int val, int it[]) {
	if (pos < l || pos > r) return ;
	it[node] += val;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val, it);
	update(node * 2 + 1, mid + 1, r, pos, val, it);
}

int query(int node, int l, int r, int u, int v, int it[]) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v, it) + query(node * 2 + 1, mid + 1, r, u, v, it);
}

main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		roi_rac.push_back(a[i]);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	ll res = 0, cur = 0;
	int r = 1;
	for (int i = 1; i <= n; i++) 
		a[i] = lower_bound(roi_rac.begin(), roi_rac.end(), a[i]) - roi_rac.begin() + 1;
	for (int i = n; i >= 1; i--) {
		s[i] = s[i + 1] + query(1, 1, n, 1, a[i] - 1, it2);
		update(1, 1, n, a[i], 1, it2);
	}
	cur = s[r];
	for (int i = 1; i <= n; i++) {
		cur += query(1, 1, n, 1, a[i] - 1, it2) + query(1, 1, n, a[i] + 1, n, it1);
		update(1, 1, n, a[i], 1, it1);
		while (r <= n && r <= i) {
			update(1, 1, n, a[r], -1, it2);
			cur -= query(1, 1, n, a[r] + 1, n, it1);
			cur -= s[r];
			r ++;
			cur += s[r];
		}
		while (r <= n && cur > k) {
			update(1, 1, n, a[r], -1, it2);
			cur -= query(1, 1, n, a[r] + 1, n, it1);
			cur -= s[r];
			r ++;
			cur += s[r];
		}
		if (r == n + 1) break;
		res += n + 1 - r;
	}
	cout << res;
}
