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
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[N + 3];

stack < int > am, duong;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 0) {
			while (am.size()) {
				int id = am.top();
				if (a[i] - 1 >= 1 - a[id]) {
					res += (1 - a[id]) * (i - id);
					a[i] = a[i] - 1 + a[id];
					a[id] = 1;
					am.pop();
				}
				else {
					res += (a[i] - 1) * (i - id);
					a[id] += a[i] - 1;
					a[i] = 1;
					break;
				}
			}
			if (a[i] > 1) duong.push(i);	
		}
		else {
			while (duong.size()) {
				int id = duong.top();
				if (a[id] - 1 >= 1 - a[i]) {
					res += (1 - a[i]) * (i - id);
					a[id] = a[id] - 1 + a[i];
					a[i] = 1;
					break;
				}
				else {
					res += (a[id] - 1) * (i - id);
					a[i] += a[id] - 1;
					a[id] = 1;
					duong.pop();
				}
			}
			if (a[i] < 1) am.push(i);
		}
	}
	if (am.size()) cout << -1 << '\n';
	else cout << res;
}