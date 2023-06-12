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

int n, a[10003], s[10003];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, greater < int >());
	if (a[1] >= n) {
		cout << "NO" << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	if (s[n] % 2 == 1) {
		cout << "NO" << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++) {
		int total_left = s[i], sum = (i * (i - 1));
		int l = i + 1, r = n, mid, ans = n + 1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (a[mid] <= i) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		sum += i * (ans - 1 - i);
		if (ans != n + 1) sum += (s[n] - s[ans - 1]);
		//cout << i << " " << total_left << " " << sum << '\n';
		if (total_left > sum) {
			cout << "NO" << '\n';
			return ;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
