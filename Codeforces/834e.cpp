#include <bits/stdc++.h>

#define int ll
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

ll l, r, res = 0, temp[10], cnt[10];

vector < ll > digitl, digitr;

bool check(int i, bool higher, bool lower) {
	if (higher && lower) return true;
	if (i == sz(digitr)) return true;
	if (!higher && !lower) {
		if (digitl[i] == digitr[i]) {
			if (cnt[digitl[i]]) {
				cnt[digitl[i]] --;
				if (check(i + 1, 0, 0)) return true;
				cnt[digitl[i]] ++;
			}
		}
		else {
			for (int j = digitl[i] + 1; j < digitr[i]; j++) if (cnt[j]) return true;
			if (cnt[digitl[i]]) {
				cnt[digitl[i]] --;
				if (check(i + 1, 0, 1)) return true;
				cnt[digitl[i]] ++;
			}
			if (cnt[digitr[i]]) {
				cnt[digitr[i]] --;
				if (check(i + 1, 1, 0)) return true;
				cnt[digitr[i]] ++;
			}
		}
	}
	else {
		if (!higher) {
			for (int j = digitl[i] + 1; j <= 9; j++) if (cnt[j]) return true;
			if (cnt[digitl[i]]) {
				cnt[digitl[i]] --;
				if (check(i + 1, 0, 1)) return true;
				cnt[digitl[i]] ++;
			}
		}
		if (!lower) {
			for (int j = 0; j < digitr[i]; j++) if (cnt[j]) return true;
			if (cnt[digitr[i]]) {
				cnt[digitr[i]] --;
				if (check(i + 1, 1, 0)) return true;
				cnt[digitr[i]] ++;
			}
		}
	}
	return false;
}

void back_track(int len, int cur) {
	if (cur > 9) {
		if (len < sz(digitr)) return ;
		for (int i = 0; i < 10; i++) cnt[i] = temp[i];
		res += check(0, 0, 0);
		return ;
	}
	for (int i = 0; i <= sz(digitl) - len; i++) {
		temp[cur] = i;
		back_track(len + i, cur + 1);	
	}
}

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> l >> r;
	while (l) {
		digitl.pb(l % 10); l /= 10;
	}
	while (r) {
		digitr.pb(r % 10); r /= 10;
	}
	while (sz(digitl) < sz(digitr)) digitl.pb(0);
	reverse(digitl.begin(), digitl.end()); reverse(digitr.begin(), digitr.end());
	back_track(0, 0);
	cout << res;
}