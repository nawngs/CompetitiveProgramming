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

ll n, k, p, q, m, a[5000003], maxr[5000003];

void sol() {
	cin >> n >> k >> p >> q >> m;
	for (int i = 1; i <= n; i++) {
		a[i] = (p * i) % m + q;
		a[i] += (k * i);
	}
	maxr[n] = a[n];
	for (int i = n - 1; i >= 1; i--) maxr[i] = max(maxr[i + 1], a[i]);
	ll ans = maxr[1];
	priority_queue < ll, vector < ll > > heap;
	for (int i = 2; i <= n; i++) {
		ll temp = maxr[i] - (i - 1) * k;
		heap.push(a[i - 1] - (i - 1) * k + n * k + (i - 2) * k);
		temp = max(temp, heap.top() - (i - 2) * k);
		ans = min(ans, temp);
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
