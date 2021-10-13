#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, b[200005], c[200005];

pii a[200005];

int main() {
	fastflow;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].se;
		b[i] = a[i].fi + a[i].se;
		c[i] = a[i].fi - a[i].se;
	}
	sort(b + 1, b + n + 1);
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++) {
		int tam = a[i].fi + a[i].se;
		int tam2 = a[i].fi - a[i].se;
		cout << max(abs(tam - b[1]), max(abs(tam - b[n]), max(abs(tam2 - c[1]), abs(tam2 - c[n])))) << " ";
	}
}
