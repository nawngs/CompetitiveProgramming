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

ll n, s, a[14], gt[20];

bool used[14];

void create() {
	gt[0] = 1;
	for (int i = 1; i <= 14; i++) gt[i] = gt[i - 1] * i;
}

void solve1() {
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int dem = 0;
		for (int j = 1; j < a[i]; j++) if (!used[j]) dem ++;
		ans += dem * gt[n - i];
		used[a[i]] = true;
	}
	cout << ans + 1 << '\n';
} 

void solve2() {
	memset(used, false, sizeof(used));
	for (int i = 1; i <= n; i++) {
		int dem = 0;
		int pre = 1;
		for (int j = 1; j <= n; j++) {
			if (!used[j]) {
				dem ++;
				pre = j;
				//cout << dem << " " << gt[n - i] << ' ' <<dem * gt[n - i] << '\n';
				if (dem * gt[n - i] >= s) break;
			}
		}
		a[i] = pre;
		s -= (dem - 1) * gt[n - i];
		used[a[i]] = true;
	}
	cout << s << '\n';
	//for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}

void sol() {
	create();
	ll x;
	while (cin >> x) a[++n] = x;
	s = a[n];
	n--;
	solve1();
	solve2();
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
