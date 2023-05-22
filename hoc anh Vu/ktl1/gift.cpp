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

const string NAME = "gift";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}


vector < pii > a1, a2;

int n, m, res[500003], s[500003];

int main() {
	fast;
	//fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int l, r, num;
		cin >> l >> r >> num;
		l++;
		r++;
		if (num == 1) a1.push_back({l, r});
		else a2.push_back({l, r});
	}
	sort(a1.begin(), a1.end());
	vector < pii > tmp;
	tmp.clear();
	if (a1.size()) {
		int l = a1[0].fi, r = a1[0].se;
		for (int i = 1; i < a1.size(); i++) {
			if (a1[i].fi <= r) r = max(r, a1[i].se);
			else {
				tmp.push_back({l, r});
				l = a1[i].fi;
				r = a1[i].se;
			} 
		}
		tmp.push_back({l, r});
	}
	tmp.push_back({INF, INF});
	int index = 0, cur = 0;
	for (int i = 1; i <= n; i++) {
		if (i == tmp[index].se + 1) {
			index ++;
			cur = !cur;
		}
		res[i] = cur;
		if (i < tmp[index].fi) cur = !cur;
		s[i] = s[i - 1] + res[i];
	}
	for (auto x : a2) {
		if (s[x.se] - s[x.fi - 1] == 0 || s[x.se] - s[x.fi - 1] == x.se - x.fi + 1) {
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << 1 << '\n';
	for (int i = 1; i <= n; i++) cout << (res[i] == 0 ? "R" : "B");
}
