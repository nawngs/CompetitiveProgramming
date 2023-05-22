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

ll aa, bb;

ll solve(ll x, const ll &a, const ll &b) {
	ll res = x - 1 + a / x;
	if (b % x == 0) res += b / x;
	else res += b / x + 1;
	return res;
}

void sol() {
	cin >> aa >> bb;
	ll res = LINF;
	for (int i = 1; i <= max(aa, bb); i++) {
		res = min(res, i - 1 + aa / i + (aa % i != 0) + bb / i + (bb % i != 0));
		/*if (i - 1 + aa / i + (aa % i != 0) + bb / i + (bb % i != 0) == 30) {
			cout << aa % i <<  " " << bb % i << '\n';
		}*/
	}
	cout <<res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}