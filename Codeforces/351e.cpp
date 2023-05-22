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

int n, p[2003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i]; 
		p[i] = abs(p[i]);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int cnt1 = 0, cnt2 = 0;
		for (int j = 1; j <= n; j++) {
			if (p[j] < p[i]) {
				if (j < i) cnt1 ++;
				else cnt2 ++;
			}
		}
		res += min(cnt1, cnt2);
	}
	cout << res;
}