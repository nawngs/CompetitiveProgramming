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

int n;

deque < pii > dq;

void sol() {
	cin >> n;
	while (n--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x, c;
			cin >> x >> c;
			dq.push_back({x, c});
		}
		else {
			int c;
			cin >> c;
			ll ans = 0;
			while (dq.size()) {
				if (c == 0) break;
				if (c >= dq.front().se) {
					ans += 1ll * dq.front().se * dq.front().fi;
					c -= dq.front().se;
					dq.pop_front();
					continue;
				}
				else {
					ans += 1ll * dq.front().fi * c;
					dq.front().se -= c;
					c = 0;
					continue;
				}
			}
			cout << ans << '\n';
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
