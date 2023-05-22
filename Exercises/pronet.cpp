#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "pronet";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n;

pii a[200003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	priority_queue < int, vector < int >, greater < int > > heap;
	int cnt = 0, res = 0;
	for (int i = n; i >= 1; i--) {
		heap.push(a[i].se);
		if (i - 1 + cnt < a[i].fi) {
			res += heap.top();
			heap.pop();
			cnt ++;
		}
	}
	cout << res << '\n';
	
}

main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
