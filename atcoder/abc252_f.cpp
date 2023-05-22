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

ll n, l, a[200003];

void sol() {
	cin >> n >> l;
	priority_queue < ll, vector < ll >, greater < ll > > heap;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		heap.push(x);
		l -= x;
	}
	ll res = 0;
	if (l > 0) heap.push(l);
	while (heap.size() > 1) {
		auto u = heap.top();
		heap.pop();
		auto v =  heap.top();
		heap.pop();
		res += u + v;
		heap.push(u + v);
	}
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
