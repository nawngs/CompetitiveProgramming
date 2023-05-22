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

const string NAME = "intersect";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 3e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Line1 {
	int x1, x2, y;
	bool operator < (const Line1 &oth) {
		return x1 < oth.x1;
	}
} a[100003];

struct Line2 {
	int y1, y2, x;
	bool operator < (const Line2 &oth) {
		return x < oth.x;
	}
} b[100003];

int n, m, it[1200003];

vector < pii > vec1;

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] += val;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

int query (int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

int main() {
	fast;
	//fre();
	cin >> n >> m;
	vector < int > roi_rac;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x1 >> a[i].x2 >> a[i].y;
		roi_rac.push_back(a[i].y);
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i].y1 >> b[i].y2 >> b[i].x;
		roi_rac.push_back(b[i].y1);
		roi_rac.push_back(b[i].y2);	
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= n; i++) a[i].y = lower_bound(roi_rac.begin(), roi_rac.end(), a[i].y) - roi_rac.begin() + 1;	
	for (int i = 1; i <= m; i++) {
		b[i].y1 = lower_bound(roi_rac.begin(), roi_rac.end(), b[i].y1) - roi_rac.begin() + 1;
		b[i].y2 = lower_bound(roi_rac.begin(), roi_rac.end(), b[i].y2) - roi_rac.begin() + 1;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	for (int i = 1; i <= n; i++) vec1.push_back({a[i].x2, i});
	sort(vec1.begin(), vec1.end());
	int ra = 0, rv = -1;
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		while (ra < n && a[ra + 1].x1 <= b[i].x) {
			ra ++;			
			update(1, 1, nmax, a[ra].y, 1);
		}
		while (rv < (int)vec1.size() - 1 && vec1[rv + 1].fi < b[i].x) {
			rv ++;
			update(1, 1, nmax, a[vec1[rv].se].y, -1);
		}
		ans += 1ll * query(1, 1, nmax, b[i].y1, b[i].y2);
		//cout << ans << '\n';
	}
	cout << ans;
}
