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

ll n, k;

pll a[200003];

void sol() {
	cin >> n >> k;
	a[0] = {1, 0};
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	priority_queue < ll, vector < ll >, greater < ll > > heap;
	ll sum_heap = 0;
	ll sum = 0;
	ll len_heap = k;
	ll res = -INF;
	for (int i = n; i >= 0; i--) {
		if (a[i].fi == 2) {
			sum += a[i].se;
			if (a[i].se < 0) {
				a[i].se = abs(a[i].se);
				if (heap.size() < len_heap) {
					heap.push(a[i].se);
					sum_heap += a[i].se;
				}
				else {
					if (!heap.empty() && heap.top() < a[i].se) {
						sum_heap = sum_heap - heap.top() + a[i].se;
						heap.pop();
						heap.push(a[i].se);
					}
				}
			}
		}
		else {
			
			res = max(res, a[i].se + sum + sum_heap);
			len_heap --;
			if (len_heap < 0) break;
			while (heap.size() > len_heap) {
				sum_heap -= heap.top();
				heap.pop();
			}
		}
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
