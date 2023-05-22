#include <bits/stdc++.h>

#define name ""
#define ll long double
#define ld ll
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

ll a1, b1, a2, b2;

ll calc(ll a, ll b) {
	ll l = 0, r = 1000, mid, ans;
	for (int time = 0; time <= 20; time++) {
		mid = (l + r) / 2;
		if (mid * b + min(mid * a, (ld)10) >= 100) {
			ans = mid;
			r = mid - EPS;
		}
		else l = mid + EPS;
	}
	return ans;
}

void sol() {
	cin >> b1 >> a1 >> b2 >> a2;
	ll res2 = calc(a1, b1), res1 = calc(a2, b2);
	//cout << res1 << " " << res2 << '\n';
	if (res1 < res2) cout << "Yunyun" << '\n';
	if (res1 == res2) cout << "Draw" << '\n';
	if (res1 > res2) cout << "Megumin" << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}