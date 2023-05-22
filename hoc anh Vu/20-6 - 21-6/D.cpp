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

const string NAME = "";
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

struct Data {
	ll a, b, c;
} a[100003];

ll A, B, C, n;

pll dpl[100003], dpr[100003];

int main() {
	fast;
	//fre();
	cin >> A >> B >> C;
	n = A + B + C;
	for (int i = 1; i <= n; i++) cin >> a[i].a;
	for (int i = 1; i <= n; i++) cin >> a[i].b;
	for (int i = 1; i <= n; i++) cin >> a[i].c;
	sort(a + 1, a + n + 1, [&](Data &x, Data &y) {
		return (x.a - x.b > y.a - y.b);
	});
	priority_queue < pll, vector < pll >, greater < pll > > heap;
	for (int i = 1; i <= A; i++) {
		dpl[A].fi += a[i].a;
		heap.push({a[i].a - a[i].c, i});
	}
	for(int i = A + 1; i <= n; i++) {
		pll u = heap.top();
		dpl[i] = dpl[i - 1];
		dpl[i].se += a[i].c;
		if (a[i].a - a[i].c > u.fi) {
			dpl[i].fi -= a[u.se].a;
			dpl[i].fi += a[i].a;
			dpl[i].se += a[u.se].c;
			dpl[i].se -= a[i].c;
			heap.pop();
			heap.push({a[i].a - a[i].c, i});
		}
	}
	while (heap.size()) heap.pop();
	for (int i = n; i > n - B; i--) {
		dpr[n - B + 1].fi += a[i].b;
		heap.push({a[i].b - a[i].c, i});
	}
	for (int i = n - B; i >= 1; i--) {
		pll u = heap.top();
		dpr[i] = dpr[i + 1];
		dpr[i].se += a[i].c;
		if (a[i].b - a[i].c > u.fi) {
			dpr[i].fi -= a[u.se].b;
			dpr[i].fi += a[i].b;
			dpr[i].se += a[u.se].c;
			dpr[i].se -= a[i].c;
			heap.pop();
			heap.push({a[i].b - a[i].c, i});
		}
	}
	ll ans = -INF;
	for (int i = A; i <= A + C; i++) {
		ans = max(ans, dpl[i].fi + dpl[i].se + dpr[i + 1].fi + dpr[i + 1].se);
	}
	cout << ans;
}
