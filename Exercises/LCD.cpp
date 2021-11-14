#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "LCD";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
/*
void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}
*/

ll n, m, a[100005], cnt[100005], s[100005];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(cnt, 0, sizeof(cnt));
	ll sum = 0, maxa = -INF;
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] <= a[i]) {
			sum += a[i] - a[i - 1];
			s[a[i - 1] + 1] += a[i - 1] + 1;
			s[a[i] + 1] -= a[i - 1] + 1;
			cnt[a[i - 1] + 1] ++;
			cnt[a[i] + 1] --;
		}
		else {
			sum += m - abs(a[i] - a[i - 1]);
			s[a[i - 1] + 1] += a[i - 1] + 1;
			cnt[a[i - 1] + 1] ++;
			int tam = a[i - 1] + 1 - m;
			s[1] += tam;
			cnt[1] ++;
			s[a[i] + 1] -= tam;
			cnt[a[i] + 1] --;
		}
	}
	for (int i = 1; i <= m; i++) {
		s[i] += s[i - 1];
		cnt[i] += cnt[i - 1];

		maxa = max(maxa, i * cnt[i] - s[i]);
	}
	cout << sum - maxa << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
