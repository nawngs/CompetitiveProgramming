#include <bits/stdc++.h>

#define name ""
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

int n, q, x, y;

vector < int > a, b, tmp;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q;
	a.resize(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	while (q--) {
		cin >> x >> y;
		b.clear();
		while(sz(tmp) < y) {
			tmp.pb(a.back());
			a.pop_back();
		}
		for (auto &c : tmp) c -= x;
		for (auto c : a) {
			while (!tmp.empty() && c >= tmp.back()) {
				b.pb(tmp.back());
				tmp.pop_back();
			}
			b.pb(c);
		}
		while (!tmp.empty()) {
			b.pb(tmp.back());
			tmp.pop_back();
		}
		a = b;
	}
	reverse(a.begin(), a.end());
	for (auto x : a) cout << x << " ";
}
