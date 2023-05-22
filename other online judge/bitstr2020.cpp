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

ll n, k, p, a[103], b[103], c[103], val[103];

ll calc(ll pos) {
	if (pos == n + 1) return 1;
	memset(val, 255, sizeof(val));
	for (int i = 1; i <= k; i++) {
		
	}
}

void sol() {
	cin >> n >> k >> p;
	for (int i = 1; i <= k; i++) 
		cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i++) {
		bool th = 1;
		for (int j = 1; j <= k; j++) 
			if (b[j] == i && c[i] == 1) {
				th = false;
				break;
			}
		ll num = calc(i + 1);
		if (th && num >= p) {

		}
		else {

		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
