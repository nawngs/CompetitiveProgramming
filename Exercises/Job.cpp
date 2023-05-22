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

const string NAME = "job";
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

pii a[100003];

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	ll res = 0, l = 0, len = 0;
	priority_queue < ll, vector < ll >, greater < ll > > heap;
	a[0].fi = a[1].fi;
	for (int i = 1; i <= n; i++) {
		while (len <= a[i].fi - l) {
			res += l + len;
			l = l + len;
			if (heap.empty()) {
				len = 2 * INF;
				break;
			}
			len = heap.top(); heap.pop();
		}
		len -= a[i].fi - l;
		heap.push(a[i].se);
		if (len > heap.top()) {
			int u = heap.top();
			heap.pop();
			heap.push(len);
			len = u;
		}
		l = a[i].fi;
 	}
 	while (1) {
 		if (len > INF) break;
 		res += l + len;
 		l = l + len;
 		if (heap.empty()) break;
 		len = heap.top(); heap.pop();
 	}
 	cout << res;
}
