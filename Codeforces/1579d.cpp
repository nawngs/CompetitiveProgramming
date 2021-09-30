#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

int n;

pll a[200005];

vector < pll > res;

void sol() {
	cin >> n;
	priority_queue < pll, vector < pll > > heap;	
	ll ans = 0;
	res.clear();
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
		if (a[i].fi != 0) heap.push(a[i]);
	}
	while (heap.size() >= 2) {
		auto tam1 = heap.top();
		heap.pop();
		auto tam2 = heap.top();
		heap.pop();
		tam1.fi --;
		tam2.fi --;
		ans ++;
		res.push_back({tam1.se, tam2.se});
		if (tam1.fi != 0) heap.push(tam1);
		if (tam2.fi != 0) heap.push(tam2);
	}
	cout << ans << '\n';
	for (auto v : res) {
		cout << v.fi << " " << v.se << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t --) sol();
}
