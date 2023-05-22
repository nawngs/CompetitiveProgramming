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

ll n;

void sol() {
	cin >> n;
	ll v = n;
	vector < int > dg;
	ll res = 0;
	while (n > 0) {
		dg.push_back(n % 10);
		n /= 10;
		res = res * 10 + 9;
	}
	res /= 10;
	reverse(dg.begin(), dg.end());
	ll cur = 0, mu = 1;;
	for (int i = 0; i < dg.size() - 1; i++) {
		cur = cur * 10 + dg[i];
		mu *= 10;
		if (dg.size() % (i + 1) == 0) {
			int sze = i + 1;
			ll temp = cur;
			while (sze < dg.size()) {
				temp = temp * mu + cur;
				sze += i + 1;
			}
			if (temp <= v) res = max(res, temp);
			sze = i + 1;
			temp = cur - 1;
			while (sze < dg.size()) {
				temp = temp * mu + (cur - 1);
				sze += i + 1;
			}
			if (temp <= v) res = max(res, temp);
		}
	}
	cout << res << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
