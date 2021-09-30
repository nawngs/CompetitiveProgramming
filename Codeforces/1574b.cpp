#include <bits/stdc++.h>

#define ll long long

using namespace std;

int t;

ll a, b, c, m;

void sol() {
	cin >> a >> b >> c >> m;
	ll maxm = a - 1 + b - 1 + c - 1;
	ll tam = max(a, max(b, c));
	ll minm = max(1ll * 0, tam - (a + b + c - tam)) - 1;
	if (minm <= m && m <= maxm) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}

int main() {
	cin >> t;
	while (t --) sol();
}