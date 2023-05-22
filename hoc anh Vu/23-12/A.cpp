#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, nxt[200003][20]; 

pii a[200003];

vector < pii > b, temp;

int get(int l, int r) {
	if (l > r) return 0;
	auto it = lower_bound(temp.begin(), temp.end(), mp(l, -1));
	pii tmp = *it;
	l = tmp.se;
	if (l == n || b[l].se > r) return 0;
	int res = 1;
	for (int j = 19; j >= 0; j--) {
		if (nxt[l][j] != n && b[nxt[l][j]].se <= r) {
			res += (1 << j);
			l = nxt[l][j];
		}
	}
	return res;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		b.pb(a[i]);
	}
	sort(b.begin(), b.end(), [&](pii &x, pii &y) {
		if (x.se != y.se) return x.se < y.se;
		return (x.fi > y.fi);
	});
	for (int i = 0; i < sz(b); i++) {
		if (sz(temp) && temp.back().fi >= b[i].fi) continue;
		temp.pb(mp(b[i].fi, i));
	}
	temp.pb(mp(INF, n));
	int cur = 0;
	for (int i = 0; i < n; i++) {
		while (cur < n && b[i].se >= b[cur].fi) cur ++;
		nxt[i][0] = cur;
	}
	nxt[n][0] = n;
	for (int j = 1; j <= 19; j++)
		for (int i = 0; i <= n; i++) {
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
		}
	vector < int > res;
	set < pii > f;
	f.insert({-1, INF});
	for (int i = 1; i <= n; i++) {
		auto it = f.upper_bound({a[i].fi + 1, -1});
		it --;
		pii val = *it;
		if (val.se < a[i].se) continue;
		if (get(val.fi, val.se) == get(val.fi, a[i].fi - 1) + get(a[i].se + 1, val.se) + 1) {
			res.push_back(i); f.erase(it);
			if (val.fi <= a[i].fi - 1) f.insert(mp(val.fi, a[i].fi - 1));
			if (a[i].se + 1 <= val.se) f.insert(mp(a[i].se + 1, val.se));
		}
	}
	cout << sz(res) << '\n';
	for (auto x : res) cout << x << " ";
}