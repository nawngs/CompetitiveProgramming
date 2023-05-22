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

ll n;

bool check[100003];

struct Data {
	ll p, d, i;
} a[100003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].p;
		a[i].i = i;
	}
	for (int i = 1; i <= n; i++) cin >> a[i].d;
	sort(a + 1, a + n + 1, [](Data &x, Data &y) {
		return (x.d < y.d) || (x.d == y.d && x.p < y.p);
	});
	ll cur = 0;
	ll res = 0;
	priority_queue < pll, vector < pll > > heap;
	memset(check, 1, sizeof(check));
	for (int i = 1; i <= n; i++) {
		cur += a[i].p;
		heap.push({a[i].p, i});
		while (cur > a[i].d) {
			auto u = heap.top();
			heap.pop();
			cur -= u.fi;
			check[u.se] = false;
		}
	}
	for (int i = 1; i<= n; i++) res += (!check[i]);
	cout << res << '\n';
	for (int i = 1; i <= n; i++) if (check[i]) cout << a[i].i << " ";
	for (int i = 1; i <= n; i++) if (!check[i]) cout << a[i].i << ' ';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
