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

int n, a[2003];

map < int, vector < int > > f;

int bs(int pos, int val) {
	int l = 0, r = f[pos].size() - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (f[pos][mid] < val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans + 1;
}	

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 2; i <= n; i++) 
		for (int j = i - 1; j >= 1; j--) {
			f[a[i] + a[j]].push_back(i);
			ans += bs(-(a[i] + a[j]), j);	
		}
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
