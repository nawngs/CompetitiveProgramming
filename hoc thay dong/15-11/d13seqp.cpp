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

int n, a[200003], L[200003], R[200003], st[200003][19];

map < int, int > pre;

int get(int l, int r) {
	int k = log2(r - l + 1);
	return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st[i][0] = a[i];
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	pre.clear();
	for (int i = 1; i <= n; i++) {
		if (pre.find(a[i]) == pre.end()) L[i] = 1;
		else L[i] = pre[a[i]] + 1;
		pre[a[i]] = i;
	}
	pre.clear();
	for (int i = n; i >= 1; i--) {
		if (pre.find(a[i]) == pre.end()) R[i] = n;
		else R[i] = pre[a[i]] - 1;
		pre[a[i]] = i;
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int l = L[i], r = i, mid, ansl, ansr;
		while (l <= r) {
			mid = (l + r) / 2;
			if (get(mid, i) == a[i]) {
				ansl = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		l = i, r = R[i];
		while (l <= r) {
			mid = (l + r) / 2;
			if (get(i, mid) == a[i]) {
				ansr = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		//cout << i << " " << L[i] << " " << R[i] << " " << (i - ansl + 1) << " " << (ansr - i + 1) << '\n';
		res += 1ll * (i - ansl + 1) * (ansr - i + 1) - 1;
	}
	cout << res;
}
