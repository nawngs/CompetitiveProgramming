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

const string NAME = "peach";
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

int n, x, y;

pii a[100003];

void sol() {
	cin >> n >> x >> y;
	y --;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;	
	sort(a + 1, a + n + 1);
	if (x < y - n) x = y - n;
	priority_queue < ll, vector < ll > > heap;
	int j = 1;
	while (j <= n && a[j].fi <= x) {
		heap.push(a[j].se);
		j ++;
	}
	ll ans = 0;
	for (int i = x; i <= y; i++) {
		while (j <= n && a[j].fi <= i) {
			heap.push(a[j].se);
			j ++;
		}
		if (heap.size()) {
			ans += 1ll * heap.top();
			heap.pop();
		}
	}
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
