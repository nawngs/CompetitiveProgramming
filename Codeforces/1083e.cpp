//[FINISHED]
#include <bits/stdc++.h>

#define int ll
#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

using Line = pii;

struct Data {
	int x, y, a;
	bool operator < (const Data &oth) {
		return x < oth.x;
	}	
} a[NMAX + 3];

int n, top = 0;

Line lines[NMAX + 3];

int get(Line a, int x) {
	return a.fi * x + a.se;
}

bool bad(Line a, Line b, Line c) {
	return (double)(a.se - b.se) / (a.fi - b.fi) > (double)(a.se - c.se) / (a.fi - c.fi);
}

void Insert(Line newline) {
	int l = 1, r = top - 1, k = top, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (bad(lines[mid - 1], lines[mid], newline)) {
			k = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	lines[k] = newline; top = k + 1;
}

int query(int x) {
	int l = 0, r = top - 1, ans = get(lines[l], x), mid;
	while (l < r) {
		mid = (l + r) / 2;
		assert(mid != top - 1);
		int v1 = get(lines[mid], x), v2 = get(lines[mid + 1], x);
		if (v1 < v2) l = mid + 1;
		else r = mid;
		//if (x == 2) cout << v1 << " " << v2 << '\n';
		ans = max(ans, max(v1, v2));
	}
	return ans;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].x >> a[i].y >> a[i].a;
	sort(a + 1, a + n + 1);
	Insert({0, 0});
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int val = query(a[i].y) + (a[i].x * a[i].y) - a[i].a;
		//cout << i << " " << val << " " << query(a[i].y) << '\n';
		res = max(res, val);
		Insert({-a[i].x, val}); 
	}
	cout << res;
}