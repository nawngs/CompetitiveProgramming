#include <bits/stdc++.h>

#define name "ex"
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
const int NMAX = 40000;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

map < ll, vector < pll > > f;

vector < pll > res;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	for (int i = 2; i <= NMAX; i++) {
		ll x = i, dem = 1;
		while (1) {	
			f[x].push_back({i, dem});
			if (dem % 2 == 0) f[x].push_back({-i, dem});
			if (LINF / x < i) break;
			x *= i; dem ++;
		}
	}	
	int t; cin >> t;
	while (t--) {
		ll x; cin >> x;
		res.clear(); res = f[x];
		res.push_back({x, 1});
		ll temp = sqrtl(x);
		if (temp * temp == x) {
			res.push_back({temp, 2}); res.push_back({-temp, 2});
		}
		temp = cbrtl(x);
		if (temp * temp * temp == x) res.push_back({temp, 3});
		sort(res.begin(), res.end()); res.erase(unique(res.begin(), res.end()), res.end());
		for (auto x : res) cout << x.fi << " " << x.se << '\n';
		cout << '\n';
	}
}