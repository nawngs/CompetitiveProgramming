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

int n;

int main() {
	fast;
	//fre();
	vector < pll > free, need;
	ll res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll a, b; cin >> a >> b;
		if (a == b) continue;
		if (a > b) {
			ll temp = a - b;
			if (need.size()) {
				while (need.size() && temp > 0) {
					ll cur = min(temp, need.back().se);
					res += cur * (i - need.back().fi);
					temp -= cur;
					need.back().se -= cur;
					if (need.back().se == 0) need.pop_back();
				}
			}
			if (temp > 0) free.push_back({i, temp});
		}
		else {
			ll temp = b - a;
			if (free.size()) {
				while (free.size() && temp > 0) {
					ll cur = min(temp, free.back().se);
					res += cur * (i - free.back().se);
					temp -= cur;
					free.back().se -= cur;
					if (free.back().se == 0) free.pop_back();
				}
				if (temp > 0) need.push_back({i, temp});
			}
 		}
	}
	cout << res;
}
