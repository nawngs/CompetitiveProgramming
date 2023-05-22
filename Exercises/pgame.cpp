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

const string NAME = "pgame";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll x, y;

bool check(ll a) {
	while (a % 2 == 0) a /= 2;
	return (a == 1);
}


void sol() {
	cin >> x >> y;
	if(!check(__gcd(x, y))) {
		cout << -1 << '\n';
		return ;
	}
	vector < pii > res;
	res.clear();
	while (x != 1 || y != 1) {
		if (res.size() > 1e5) {
			cout << -1 << '\n';
			return ;
		}
		if (x % 2 == 1 && y % 2 == 1) {
			if (x == 1) {
				y += x;
				res.push_back({4, 1});
			}
			else {
				if (y == 1) {
					x += y;
					res.push_back({3, 1});
				}
				else {
					if (x < y) {
						y += x;
						res.push_back({4, 1});
					}
					else {
						x += y;
						res.push_back({3, 1});
					}
				}
			}
		} 
		while (x % 2 == 0) {
			x /= 2;
			res.push_back({1, -1});
		}
		while (y % 2 == 0) {
			y /= 2;
			res.push_back({2, -1});
		}
	}
	if (res.size() > 1e5) {
			cout << -1 << '\n';
			return ;
		} 
	cout << res.size() << '\n';
	reverse(res.begin(), res.end());
	for (auto x : res) {
		cout << x.fi;
		if (x.se != -1) cout << " " << x.se;
		cout << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
