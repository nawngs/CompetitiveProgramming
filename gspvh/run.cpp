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

const string NAME = "run";
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

int n, a[1000003], k;

int main() {
	fast;
	fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int dem = 0;
	for (int i = 1; i < n; i++) 
		dem += (a[i] > a[i + 1]);
	dem += (a[n] > a[1]);
	if (dem <= k) {
		cout << n << '\n';
		for (int i = 1; i <= n; i++) 
			cout << i << " ";
		return 0;
	}
	if (dem > k + 1) {
		cout << 0 << '\n';
		return 0;
	}
	vector < int > res;
	for (int i = 1; i < n; i++) 
		if (a[i] > a[i + 1]) 
			res.push_back(i + 1);
	if (a[n] > a[1])
	 res.push_back(1);
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for (auto x : res) cout << x << " ";
}
