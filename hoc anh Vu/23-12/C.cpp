#include <bits/stdc++.h>

#define name ""
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

bool dp[100003];

int trace[100003];

int n;

pii a[303];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	ll total = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
		total += a[i].fi;	
	}
	sort(a + 1, a + n + 1);
	int s = 0, pos = -1, val = 0;;
	dp[0] = 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j <= total / 2; j++) {
			if (dp[j] == 0) continue;
			if (j + a[i].fi <= total / 2) continue;
			if (val < j + a[i].fi) {
				val = j + a[i].fi;
				pos = i;
			}
		}
		for (int j = s; j >= 0; j--) {
			if (dp[j] && !dp[j + a[i].fi])
				dp[j + a[i].fi] = 1;
		}
		s += a[i].fi;
	}
	for (int i = 0; i < total; i++) dp[i] = 0;
	dp[0] = 1;
	s = 0;
	for (int i = n; i > pos; i--) {
		for (int j = s; j >= 0; j--) {
			if (dp[j] && !dp[j + a[i].fi]) {
				dp[j + a[i].fi] = 1;
				trace[j + a[i].fi] = i;
			}
		}
		s += a[i].fi;
	}
	vector < int > res;
	res.push_back(a[pos].se);
	val -= a[pos].fi;
	while (val != 0) {
		res.push_back(a[trace[val]].se);
		val -= a[trace[val]].fi;
	}
	cout << res.size() << '\n';
	for (auto x : res) cout << x << " ";
}