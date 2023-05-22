#include <bits/stdc++.h>

#define int ll
#define name "crect"
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

int n;

ll dp[5003];

pii a[5003], b[5003];

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi >> a[i].se;
		a[i].fi = abs(a[i].fi); a[i].se = abs(a[i].se);
	}
	sort(a + 1, a + n + 1);
	stack < int > st;
	for (int i = 1; i <= n; i++) {
		while (st.size() && a[st.top()].se <= a[i].se) 
			st.pop();
		st.push(i);
	}
	n = 0;
	while (st.size()) 
		b[++ n] = a[st.top()], st.pop();
	sort(b + 1, b + n + 1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = LINF;
		for (int j = i; j >= 1; j--) 
			dp[i] = min(dp[i], dp[j - 1] + b[i].fi * b[j].se * 4);
	}
	cout << dp[n];
}