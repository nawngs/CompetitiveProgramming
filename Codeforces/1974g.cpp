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
const int N = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, x, a[N + 3];

void sol() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int cur = 0, res = 0;
	priority_queue < int > heap;
	for (int i = 1; i <= n; i++) {
		if (cur >= a[i]) {
			cur -= a[i];
			heap.push(a[i]);
			res ++;
		}
		else {
			if (heap.size()) {
				if (heap.top() > a[i]) {
					cur += heap.top();
					cur -= a[i];
					heap.pop(); heap.push(a[i]);
				}
			}
		}
		cur += x;
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}