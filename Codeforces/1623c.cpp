#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[200005], b[200005];

bool check(int x) {
	for (int i = 1; i <= n; i++) a[i] = b[i]; 
	for (int i = 3; i <= n; i++) {
		if (a[i - 2] < x) {
			int tam = x - a[i - 2];
			tam += tam % 2;
			tam /= 2;
			a[i] -= tam * 3;
			a[i - 1] += tam;
			a[i - 2] += 2 * tam;
			if (a[i] < 0) return false;
		}
		if (a[i - 1] < x) {
			int tam = min(a[i], (x - a[i - 1]) * 3);
			tam /= 3;
			a[i] -= 3 * tam;
			a[i - 1] += tam;
			a[i - 2] += 2 * tam;
		}
	}
	for (int i = 1; i <= n; i++) 
		if (a[i] < x) return false;
	
	return true;
}


void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> b[i];
	int l = 1, r = 1e9, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
