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

int m, n, p[65540];

bool cnt[65540];

int calc(int l, int r) {
	if (l == r) return 1;
	int mid = l + (r - l + 1) / 2 - 1;
	bool th = 1;
	memset(cnt, false, sizeof(cnt));
	for (int i = l; i <= mid; i++) cnt[p[i]] = 1;
	for (int i = mid + 1; i <= r; i++)
	 	if (cnt[p[i]]) {
			th = false;
			break;
		}
	if (th) return (calc(l, mid) * calc(mid + 1, r)) % MOD;
	else {
		for (int i = l; i <= mid; i++) if (p[i] != p[i + (r - l + 1) / 2]) return 0;
		return (calc(l, mid) * 2) % MOD;
	}
}

main() {
	fast;
	cin >> m >> n;
	for (int i = 0; i < (1 << m); i++) cin >> p[i];
	cout << calc(0, (1 << m) - 1);
}
