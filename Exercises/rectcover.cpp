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

const string NAME = "rectcover";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".in";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, A;

pii a[103];

bool covered[103];

int main() {
	fast;
	fre();
	cin >> n >> A;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (covered[i]) continue;
		covered[i] = 1;	
		res ++;
		int height = a[i].se;
		for (int j = i + 1; j <= n; j++) {
			if (covered[j]) continue;
			if ((a[j].fi - a[i].fi) * max(height, a[j].se) <= A) {
				covered[j] = 1;
				height = max(height, a[j].se);
			}
		}
	}
	cout << res;
}
