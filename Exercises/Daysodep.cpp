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

const string NAME = "daysodep";
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

ll n, k, s[200003], odd[200003], even[200003];

namespace sub1 {
	ll res = 0;
	void solve() {
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < i; j++) {
				if (s[i] - s[j] >= 0 && s[i] - s[j] <= k && even[i] > even[j] && odd[i] > odd[j]) 
					res ++;	
			}
		cout << res << '\n';
	}
}

namespace sub2 {
	map < ll, vector < int > > f;
	ll res = 0;
	void solve() {
		f[0].push_back(0);
		for (int i = 1; i <= n; i++) {
			f[s[i]].push_back(i);
			int l = 0, r = i - 1, mid, ans = -1;
			while (l <= r) {
				mid = (l + r) / 2;
				if (even[i] > even[mid] && odd[i] > odd[mid]) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			if (ans == -1) continue;
			for (int j = s[i]; j >= s[i] - k; j--) {
				if (f[j].empty()) continue;
				auto id = upper_bound(f[j].begin(), f[j].end(), ans);
				if (id == f[j].end()) res += f[j].size();
				else res += id - f[j].begin();
			}
		}
		cout << res << '\n';
	}
}

int main() {
	fast;
	fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (s[i] % 2 == 1) {
			s[i] = -s[i];
			odd[i] = 1;
		}
		else even[i] = 1;
		s[i] += s[i - 1];even[i] += even[i - 1]; odd[i] += odd[i - 1];
	}
	if (n <= 2000) sub1::solve();
	else 
		sub2::solve();
}
