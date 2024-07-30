#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int val[NMAX + 3]; // 0 ch xac dinh 1 true -1 false

string s;

void sol() {
	cin >> s; int n = s.size();
	for (int i = 0; i <= n; i++) val[i] = 0;
	val[0] = val[1] = 1;
	int cur = 0;
	for (auto c : s) {
		if (c == '0') {
			if (val[cur] == 1) {
				cout << "NO" << '\n';
				return ;
			}
			val[cur] = -1;
		}
		if (c == '1') {
			if (val[cur] == -1) {
				cout << "NO" << '\n';
				return ;
			}
			val[cur] = 1;
		}
		if (c == '+') cur ++;
		if (c == '-') {
			if (cur >= 2) val[cur] = 0;
			cur --;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}