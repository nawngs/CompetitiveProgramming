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

using Line = pll;

ll n, a[200003], s[200003], ss[200003], top = 0;

Line lines[200003];

ll get(Line a, ll x) {
	return a.fi * x + a.se;
}

bool bad(Line a, Line b, Line c) {
	return (double)(a.se - b.se) / (a.fi - b.fi) >= (a.se - c.se) / (a.fi - c.fi);
}

void Insert(Line newline) {
	int l = 1, r = top - 1, mid, k = top;
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

main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		ss[i] = ss[i - 1] + s[i];
	}
	ll res = 0;
	Insert({0, 0});
	for (int i = 1; i <= n; i++) {
		res = max(res, query(s[i]) + i * s[i] - ss[i - 1]);
		Insert({-i, ss[i - 1]});
	}
	cout << res;
}
