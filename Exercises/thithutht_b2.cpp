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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	deque < int > dq;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (!dq.size()) {
			dq.push_back(x);
			continue;
		}
		while (dq.size() && dq.back() == x) {
			dq.pop_back();
			x ++;
		}
		dq.push_back(x);
	}
	cout << dq.size() << '\n';
	while (dq.size()) {
		cout << dq.front() << " ";
		dq.pop_front();
	}
}
