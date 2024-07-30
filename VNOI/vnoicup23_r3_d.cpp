//[FINISHED]
#include <bits/stdc++.h>

#define name ""
#define int ll
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
const int NMAX = 3e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k, s[NMAX + 3], top = 0, a[NMAX + 3], cnt[NMAX + 3], t[NMAX + 3];

vector < int > pos[NMAX + 3];

using Line = pll;

Line lines[NMAX + 3];

ll get(Line a, ll x) {
	return a.fi * x + a.se;
}

bool bad(Line a, Line b, Line c) {
	return (double)(a.se - b.se) / (a.fi - b.fi) >= (double)(a.se - c.se) / (a.fi - c.fi);
}

void Insert(Line newline) {
	int l = 0, r = top - 1, mid, k = top;
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

ll query(ll x) {
	int l = 0, r = top - 1, mid, ans = get(lines[l], x);
	while (l < r) {
		mid = (l + r) / 2;
		int v1 = get(lines[mid], x), v2 = get(lines[mid + 1], x);
		if (v1 < v2) l = mid + 1;
		else r = mid;
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
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		pos[t[i]].pb(i);
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	ll res = 0;
	int l = 1, val = 0, dem = 0;
	for (int r = 1; r <= n; r++) {
		cnt[t[r]] ++; val += a[r];
		if (cnt[t[r]] == 1) dem ++;
		while (dem == k) {
			val -= a[l]; cnt[t[l]] --;
			if (!cnt[t[l]]) dem --;
			l ++;
		}
		res = max(res, val);
	}
	for (int i = 1; i <= k; i++) if (SZE(pos[i])) {
		top = 0;
		Insert({-k, 0});
		ll cur = 0;
		for (auto id : pos[i]) {
			cur += a[id];
			res = max(res, query(cur) + s[i]);
			Insert({-k, k * cur - s[i]});
		}
	}
	cout << res;
}