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

const string NAME = "discounts";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 220797;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k;

pll a[nmax + 3];

vector < pii > Green, Milk;

vector < int > res[nmax + 3];

int main() {
	fast;
	fre();
	int O; cin >> O;
	cin >> n >> k;
	ld total = 0;
	for (int i = 1; i <= n; i++) {
		int p, t;
		cin >> p >> t;
		if (t == 1) Green.push_back({p, i});
		else Milk.push_back({p, i});
		a[i] = {p, t};
	}
	sort(Green.begin(), Green.end());
	for (int i = 1; i < k; i++) {
		if (Green.size()) {
			res[i].push_back(Green.back().se);
			Green.pop_back();
		}
	}
	if (Green.size()) {
		res[k].push_back(Green[0].se);
		for (int i = 1; i < Green.size(); i++) 
			res[k].push_back(Green[i].se);
	}
	for (int i = k; i >= 1; i--) {
		if (res[i].empty()) {
			res[i].push_back(Milk.back().se);
			Milk.pop_back();
		}
		else break;
	}
	for (auto x : Milk) 
		res[k].push_back(x.se);
	for (int i = 1; i <= k; i++) {
		ll temp = LINF;
		bool valid = 0;
		for (auto x : res[i]) {
			total += a[x].fi;
			temp = min(temp, a[x].fi);
			if (a[x].se == 1) valid = 1;
		}
		if (valid) total -= (ld) temp / 2;
	}
	cout << fixed << setprecision(1) << total << '\n';
	for (int i = 1; i <= k; i++) {
		cout << res[i].size() << " ";
		for (auto x : res[i]) cout << x << " ";
		cout << '\n';
	}
}
