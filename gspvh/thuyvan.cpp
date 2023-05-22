#include <bits/stdc++.h>

#define name "thuyvan"
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
const pll MOD = {1e9 + 7, 1000992299};
const ll BASE = 2309;

ll n, k;

pll hashs[55][200003], pw[200003];

string s[55], res;

map < pii, int > cnt;

map < pii, bool > exist;

pii get(int l, int r, int id) {
	int val1 = (hashs[id][r].fi - hashs[id][l - 1].fi * pw[r - l + 1].fi + MOD.fi * MOD.fi) % MOD.fi;
	int val2 = (hashs[id][r].se - hashs[id][l - 1].se * pw[r - l + 1].se + MOD.se * MOD.se) % MOD.se;
	return mp(val1, val2);
}

bool check(int len) {
	cnt.clear();
	for (int i = 1; i <= n; i++) {
		exist.clear();
		for (int j = len; j < sz(s[i]); j++) {
			pii val = get(j - len + 1, j, i);
			if (exist.find(val) != exist.end()) continue;
			exist[val] = 1;
			cnt[val] ++;
			if (cnt[val] >= k) {
				res = "";
				for (int p = j - len + 1; p <= j; p++)
					res += s[i][p];
				return true;
			}
		}
	}
	return false;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i]; s[i] = ' ' + s[i];
		hashs[i][0].fi = hashs[i][0].se = 0;
		for (int j = 1; j < sz(s[i]); j++) {
			hashs[i][j].fi = (hashs[i][j - 1].fi * BASE + s[i][j]) % MOD.fi;
			hashs[i][j].se = (hashs[i][j - 1].se * BASE + s[i][j]) % MOD.se;
		}
	}
	pw[0].fi = pw[0].se = 1;
	for (int i = 1; i <= NMAX; i++) {
		pw[i].fi = (pw[i - 1].fi * BASE) % MOD.fi;
		pw[i].se = (pw[i - 1].se * BASE) % MOD.se;
	}
	int l = 1, r = NMAX, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << res;
}