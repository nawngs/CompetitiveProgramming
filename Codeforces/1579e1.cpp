#include <bits/stdc++.h>

#define ll long long
#define fi first 
#define se second
#define pll pair < ll, ll >

using namespace std;

const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1;

ll n, a[200005];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	deque < ll > dq;
	dq.push_back(a[1]);
	for (int i = 2; i <= n; i++) {
		if (a[i] < dq.front()) dq.push_front(a[i]);
		else dq.push_back(a[i]);
	}
	while (dq.size()) {
		cout << dq.front() << " ";
		dq.pop_front();
	}
	cout << '\n';
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while (t --) sol();
}
