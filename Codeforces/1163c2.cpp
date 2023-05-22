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

struct Point {
	ll x, y;
} P[1003];

map < pll, set < ll > > f;

int n;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> P[i].x >> P[i].y;
	ll res = 0, dem = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			ll a = P[i].y - P[j].y, b = P[j].x - P[i].x;
			ll temp = __gcd(a, b); a /= temp; b /= temp;
			if (a < 0 || (a == 0 && b < 0)) a = -a, b = -b;
			ll c = a * P[i].x + b * P[i].y;
			if (!f[mp(a, b)].count(c)) {
				res += dem - sz(f[mp(a, b)]);
				dem ++; f[mp(a, b)].insert(c);
			}
		}
	cout << res;
}