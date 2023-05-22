#include <bits/stdc++.h>

#define name "lucky"
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

ll n, a, b, c, d;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> a >> b >> c >> d;
	ll res = 0;
	for (int i = 1; i <= d; i++)
		for (int j = 1; j <= d; j++) {
			int val1 = __gcd(i, j);
			int val2 = i * j / val1;
			if (a <= val1 && val1 <= b && c <= val2 && val2 <= d) res = (res + 1) % MOD;
		}
	cout << res;
}