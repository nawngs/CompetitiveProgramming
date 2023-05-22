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

ll n, k, a[100003], dem[30];

string s, t;

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> s >> t;
	s = ' ' + s; t = ' ' + t;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		res += a[i];
	}
	vector < pll > pos;
	for (int i = 1; i <= n; i++) {
		dem[s[i] - 'a'] ++; dem[t[i] - 'a'] --;
		bool ok = true;
		for (int j = 0; j < 26; j++) if (dem[j] != 0) {
			ok = false;
			break;
		}
		if (!ok) continue;
		if (s[i] == t[i] && ok) {
			pos.push_back({a[i], i});
			res -= a[i];
		}
	}
	if (sz(pos) == 0) {
		cout << res << '\n';
		return 0;
	}
	ll need = (pos[0].se != 1) + (pos.back().se != n);
	for (int i = 1; i < sz(pos); i++) if (pos[i].se - pos[i - 1].se > 1) need ++;
	int id = 0;
	vector < ll > val;
	while (id < sz(pos)) {
		int left = pos[id].se;
		ll s = pos[id].fi;
		while (id < sz(pos) - 1 && pos[id + 1].se == pos[id].se + 1) s += pos[++ id].fi;
		if (left != 1 && pos[id].se != n) val.push_back(s);
		id ++;
	}
	sort(val.begin(), val.end());
	for (int i = 0; i < min(1ll * sz(val), need - k); i++) res += val[i];
	cout << res;
}