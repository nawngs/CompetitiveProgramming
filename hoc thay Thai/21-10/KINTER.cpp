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

ll n, k;

pll a[100003];

int main() {
	fast;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	ll res = 0;
	multiset < ll > ms;
	for (int i = 1; i < k; i++) 
		ms.insert(a[i].se);
	for (int i = k; i <= n; i++) {
		ms.insert(a[i].se);
		res = max(res, *ms.begin() - a[i].fi);
		ms.erase(ms.begin());
	}
	cout << res;
}
