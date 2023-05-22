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

const string NAME = "compress";
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

int nn[100003], kk[100003], xx[100003], t;

vector < int > s[100003];

bool used[100003];

namespace sub1 {
	void solve() {
		for (int test = 1; test <= t; test++) {
			ll n = nn[test], k = kk[test], x = xx[test];
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++)
					used[j] = false;
				used[i] = 1;
				int pre = i;
				bool th = 1;
				for (int j = 1; j < n; j++) {
					int temp = s[test][j] - pre;
					if (temp > n || temp <= 0 || used[temp]) {
						th = false;
						break;
					}
					used[temp] = 1;
					pre = temp;
				}
				if (!th) continue;
				x --;
				if (x == 0) {
					pre = i;
					for (int j = 1; j < n; j++) {
						cout << pre << " ";
						int temp = s[test][j] - pre;
						used[temp] = 1;
						pre = temp;
					}
					cout << pre << '\n';
					break;
				}
			}
			if (x) cout << -1 << '\n';
		}
	}
}

int main() {
	fast;
	//fre();
	cin >> t;
	int total = 0;
	for (int i = 1; i <= t; i++) {
		cin >> nn[i] >> kk[i] >> xx[i];
		s[i].resize(nn[i] + 1);
		for (int j = 1; j <= nn[i] - kk[i] + 1; j++) 
			cin >> s[i][j];
		total += nn[i];
	}
	if (total <= 5000) sub1::solve();
		// else 
		// 	sub2::solve();

}
