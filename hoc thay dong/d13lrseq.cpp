#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll LINF = 1E17;

ll n, L, R, s[100003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> L >> R;
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		s[i] = s[i - 1] + x;
	}
	deque < ll > dq;
	ll res = -LINF;
	for (int i = L; i <= n; i++) {
		while (!dq.empty() && s[dq.front()] >= s[i - L]) dq.pop_front();
		dq.push_front(i - L);
		while (dq.back() < i - R) dq.pop_back();
		res = max(res, s[i] - s[dq.back()]);
	}
	cout << res;
}
