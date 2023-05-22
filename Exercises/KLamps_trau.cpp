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

int n, dem = 0, k;

pii a[103];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	for (int i = 4; i <= n; i++) {
		for (int j = i - 1; j >= 3; j--) {
			for (int p = j - 1; p >= 2; p--) {
				for (int q = p - 1; q >= 1; q--) {
					int cnt[30];
					memset(cnt, 0, sizeof(cnt));
					cnt[a[i].fi] ++;
					cnt[a[i].se + 1] --;
					cnt[a[j].fi] ++;
					cnt[a[j].se + 1] --;
					cnt[a[p].fi] ++;
					cnt[a[p].se + 1] --;
					cnt[a[q].fi] ++;
					cnt[a[q].se + 1] --;
					for (int pos = 1; pos <= 25; pos ++) {
						cnt[pos] += cnt[pos - 1];
						if (cnt[pos] == 4) {
							dem ++;
							break;
						}
					}
				}
			}
		}
	}
	cout << dem;
}
