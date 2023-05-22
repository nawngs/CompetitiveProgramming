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

const string NAME = "shopping";
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

int n, q, a[100003], res[100003];

struct Query {
	int l, u, v, k, id;
} Q[100003];

vector < int > roi_rac, pos[300003];

ll it[400003];

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] += 1ll * val;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
} 

ll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return(query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v));
}

signed main() {
	fast;
	fre();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		roi_rac.push_back(a[i]);
	}
	for (int i = 1; i <= q; i++) {
		cin >> Q[i].l >> Q[i].u >> Q[i].v >> Q[i].k;
		Q[i].id = i;
		roi_rac.push_back(Q[i].u);
		roi_rac.push_back(Q[i].v);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(roi_rac.begin(), roi_rac.end(), a[i]) - roi_rac.begin();
		pos[a[i]].push_back(i);
	}
	sort(Q + 1, Q + q + 1, [&](Query &x, Query &y) {
		return x.v < y.v;
	});
	Q[0].v = -1;
	for (int i = 1; i <= q; i++) {
		Q[i].v = lower_bound(roi_rac.begin(), roi_rac.end(), Q[i].v) - roi_rac.begin();
		for (int j = Q[i - 1].v + 1; j <= Q[i].v; j++) {
			for (auto x : pos[j]) 
				update(1, 1, n, x, roi_rac[a[x]]);
		}
		int l = Q[i].l, r = n, mid, ans = Q[i].l - 1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (query(1, 1, n, Q[i].l, mid) <= Q[i].k) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}	
		res[Q[i].id] = ans - Q[i].l + 1;
	}
	for (int i = 1; i <= q; i++)
		cout << res[i] << '\n';
}
