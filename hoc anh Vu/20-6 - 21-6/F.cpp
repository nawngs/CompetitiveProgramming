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
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[300003], res[300003], st[300003][19];

int query(int l, int r) {
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
	for (int j = 1; 1 << j <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	int kq = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i, mid, ans, ans2;
		while (l <= r) {
			mid = (l + r) / 2;
			if (query(mid, i) == a[i]) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		l = i, r = n;
		while (l <= r) {
			mid = (l + r) / 2;
			if (query(i, mid) == a[i]) {
				ans2 = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		kq = max(kq, ans2 - ans);
		res[ans] = max(res[ans], ans2 - ans);
		//cout << ans << " " << res[ans] << '\n';
	}
	vector < int > valid;
	for (int i = 1; i <= n; i++) if (res[i] == kq) valid.push_back(i);
	cout << valid.size() << " " << kq << '\n';
	for (auto x : valid) cout << x << " ";
}
