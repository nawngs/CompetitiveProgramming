#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, dp[500005];

pll a[500005];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		dp[i] = INF;
	}
	dp[0] = 0;
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	for (int i = 1; i <= n; i++) {
		heap.push({dp[i - 1] + a[i].se, a[i].fi});
		while (heap.size() && heap.top().se < i) heap.pop();
		dp[i] = heap.top().fi;
	}
	cout << dp[n];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
