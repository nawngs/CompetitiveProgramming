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

const string NAME = "mball1";
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
	fre();
	cin >> n;
	vector < int > free;
	vector < int > need;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == 1) continue;
		if (x == 0) {
			if (free.size()) {
				res += 1ll * i - free.back();
				free.pop_back();
			}
			else need.push_back(i);
		}
		if (x > 1) {
			while (x > 1 && need.size()) {
				res += 1ll * i - need.back();
				need.pop_back();
				x --;
			}
			while (x > 1) {
				free.push_back(i);
				x --;
			}
		}
	}
	cout << res;
}
