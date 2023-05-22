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

int n, m;

multiset < pii > pos;

multiset < pii > dist;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		if (c == 'E') {
			pii res;
			if (pos.empty()) {
				res = mp(1, 1);
				pos.insert(res);
				cout << res.fi << " " << res.se << '\n';
				continue;
			}
			if (sz(pos) == 1) {
				res = mp(n, 2);
				pos.insert(res);
				dist.insert({1 - n, 1});
				cout << res.fi << " " << res.se << '\n';
				continue;
			}
			pii temp = *pos.rbegin();
			ll lst = (n - temp.fi) * (n - temp.fi) + 1;
			temp = *dist.begin(); temp.fi = -temp.fi;
			ll len = (temp.fi / 2) * (temp.fi / 2);
			if (temp.fi % 2 == 1) len += 1;
			if (lst > len) {
				res.fi = n, res.se = (pos.rbegin()->se == 1 ? 2 : 1); 
				dist.insert({n - pos.rbegin()->fi, pos.rbegin()->fi});
				cout << res.fi << " " << res.se << '\n';
				pos.insert(res);
			}
			else {
				
			}
		}
	}
	//int t; cin >> t; while (t --) sol();
}