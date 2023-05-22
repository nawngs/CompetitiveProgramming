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

const string NAME = "SUMMINMAX";
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

int n, a[1000003];

int getmax(int l, int r) {
	if (l == r) return a[l];
	int mid = (l + r) / 2;
	return max(getmax(l, mid), getmax(mid + 1, r));
}

int getmin(int l, int r) {
	if (l == r) return a[l];
	int mid = (l + r) / 2;
	return min(getmin(l, mid), getmin(mid + 1, r));
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << getmax(1, n) + getmin(1, n);	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
