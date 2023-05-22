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

const string NAME = "dlight";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 3e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, t, cnt[300003];

pii a[100003];

int main() {
	fast;
	fre();
	cin >> n >> t;
	vector < int > roi_rac;
	roi_rac.push_back(1); roi_rac.push_back(n + 1);
	for (int i = 1; i <= t; i++) {
		cin >> a[i].fi >> a[i].se;
		a[i].se += 1;
		roi_rac.push_back(a[i].fi);
		roi_rac.push_back(a[i].se);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= t; i++) {
		a[i].fi = lower_bound(roi_rac.begin(), roi_rac.end(), a[i].fi) - roi_rac.begin();
		a[i].se = lower_bound(roi_rac.begin(), roi_rac.end(), a[i].se) - roi_rac.begin();
		cnt[a[i].fi] ++;
		cnt[a[i].se] --;
	}
	ll res = 0;
	for (int i = 0; i < roi_rac.size() - 1; i++) {
		if (i != 0) cnt[i] = ((cnt[i - 1] + cnt[i]) % 3 + 3) % 3;
		cnt[i] %= 3;
		if (cnt[i] == 0) res += 1ll * (roi_rac[i + 1] - roi_rac[i]);
	}
	cout << res;
}
