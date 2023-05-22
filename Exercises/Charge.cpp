#include <bits/stdc++.h>

#define name "charge"
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

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) {
		ll x; cin >> x;
		ll cur = 1, s = 0;
		vector < ll > res;
		while (s < x) {
			s += cur;
			res.push_back(cur);
			cur *= 2;
		}
		if (s < x) res.push_back(x - s);
		sort(res.begin(), res.end());
		cout << res.size() << '\n';
		for (auto x : res) cout << x << " ";
		cout << '\n';
	}

}