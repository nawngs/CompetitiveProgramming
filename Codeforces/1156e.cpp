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

int n, a[200003], pos[200003], l[200003], r[200003], res = 0;

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	a[0] = a[n + 1] = INF;
	for (int i = 1; i <= n; i++) {
		l[i] = i - 1;
		while (a[i] > a[l[i]]) l[i] = l[l[i]];
	}
	for (int i = n; i >= 1; i--) {
		r[i] = i + 1;
		while (a[i] > a[r[i]]) r[i] = r[r[i]];
	}
	for (int i = 1; i <= n; i++) {
		if (l[i] + 1 == i || r[i] + 1 == i) continue;
		if (i - l[i] < r[i] - i) {for (int j = l[i] + 1; j < i; j++) if (pos[a[i] - a[j]] > i && pos[a[i] - a[j]] < r[i]) res ++;}
		else for (int j = i + 1; j < r[i]; j++) if (pos[a[i] - a[j]] < i && pos[a[i] - a[j]] > l[i]) res ++;
	}
	cout << res;
}
