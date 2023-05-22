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

const string NAME = "inedg";
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

int n;

map < int, vector < int > > fx;

map < int, vector < int > > fy;

int bs1(int x, vector < int > f) {
	int l = 0, r = f.size() - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (f[mid] >= x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int bs2(int x, vector < int > f) {
	int l = 0, r = f.size() - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (f[mid] <= x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	} 
	return ans;
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		pii a;
		cin >> a.fi >> a.se;
		fx[a.fi].push_back(a.se);
		fy[a.se].push_back(a.fi);
	}
	for (auto &x : fx) 
		sort(x.se.begin(), x.se.end());
	for (auto &x : fy)
		sort(x.se.begin(), x.se.end());
	int p; cin >> p;
	while (p--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int tmp1 = 0, tmp2 = 0, res = 0;
		tmp1 = bs1(y1, fx[x1]);
		tmp2 = bs2(y2, fx[x1]);
		if (tmp1 != -1 && tmp2 != -1 && tmp2 >= tmp1) 
			res += tmp2 - tmp1 + 1;
		tmp1 = bs1(y1, fx[x2]);
		tmp2 = bs2(y2, fx[x2]);
		if (tmp1 != -1 && tmp2 != -1 && tmp2 >= tmp1) 
			res += tmp2 - tmp1 + 1;
		tmp1 = bs1(x1 + 1, fy[y1]);
		tmp2 = bs2(x2 - 1, fy[y1]);
		if (tmp1 != -1 && tmp2 != -1 && tmp2 >= tmp1) 
			res += tmp2 - tmp1 + 1;
		tmp1 = bs1(x1 + 1, fy[y2]);
		tmp2 = bs2(x2 - 1, fy[y2]);
		if (tmp1 != -1 && tmp2 != -1 && tmp2 >= tmp1) 
			res += tmp2 - tmp1 + 1;
		cout << res << '\n';
	}
}
