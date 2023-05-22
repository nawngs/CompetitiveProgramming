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

ll n, s1, s2;

pll r[200003];

void sol() {
	cin >> n >> s1 >> s2;
	for (int i = 1; i <= n; i++) {
		cin >> r[i].fi; 
		r[i].se = i;
	}
	sort(r + 1, r + n + 1);
	ll cur1 = 0, cur2 = 0;
	vector < ll > res1, res2;
	for (int i = 1; i <= n; i++) {
		if (cur1 + s1 < cur2 + s2) {
			res1.push_back(r[i].se);
			cur1 += s1;
		}
		else {
			res2.push_back(r[i].se);
			cur2 += s2;
		}
	}
	cout << sz(res1) << " "; reverse(res1.begin(), res1.end());
	for (auto x : res1) cout << x << " ";
	cout << '\n';
	cout << sz(res2) << " "; reverse(res2.begin(), res2.end());
	for (auto x : res2) cout << x << " ";
	cout << '\n';

}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}