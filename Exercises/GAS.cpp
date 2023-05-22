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

const string NAME = "GAS";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k;

vector < int > c;

void sol() {
	cin >> n >> k;
	c.resize(n);
	for (auto &x : c) cin >> x;
	deque < pii > dq;
	dq.push_front({c[0], k});
	ll ans = 0;
	for (int i = 1; i < c.size(); i++) {
		ans += dq.front().fi;
		dq.front().se --;
		if (dq.front().se == 0) dq.pop_front();
		ll cnt = 1;
		while (dq.size() && dq.back().fi > c[i]) {
			cnt += dq.back().se;
			dq.pop_back();
		}
		dq.push_back({c[i], cnt});
	}
	ans += dq.front().fi;
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
