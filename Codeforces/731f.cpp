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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[200003], cnt[200003];

bool exist[200003];

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]] ++;
		exist[a[i]] = 1;
	}
	for (int i = 1; i <= nmax; i++)
		cnt[i] += cnt[i - 1];
	ll res = 0;
	for (int i = 1; i <= nmax; i++)
		if (exist[i]) {
			ll s = 0;
			for (int j = i; j <= nmax; j+=i)
				s += (cnt[min(1ll * j + i - 1, nmax)] - cnt[j - 1]) * j;
		res = max(res, s);
		}
	cout << res;
}
