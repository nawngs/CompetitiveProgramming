#include <bits/stdc++.h>

#define name "xmas"
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

ll n, k, a[500003], dp[103][103];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		stack < int > st;
		for (int i = l; i <= r; i++) {
			if (sz(st) && st.top() + a[i] == k) {
				st.pop();
				continue;
			}
			st.push(a[i]);
		}
		if (st.empty()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}