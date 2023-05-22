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

const string NAME = "maxsegment";
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

int n, k, a[500003], t;

deque < pii > dq;

int main() {
	fast;
	fre();
	cin >> t;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i < k; ++i) {
		while (dq.size() && dq.back().fi < a[i]) dq.pop_back();
		dq.push_back({a[i], i});
	}
	for (int i = k; i <= n; ++i) {
		while (dq.size() && dq.front().se < i - k + 1) dq.pop_front();
 		while (dq.size() && dq.back().fi < a[i]) dq.pop_back();
		dq.push_back({a[i], i});
		cout << dq.front().fi << ' ';
	}
}