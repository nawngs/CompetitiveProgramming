#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define ld long double

using namespace std;

using vi = vector < int >;

int n, m, cnt[103][26];

ld C[103][103];

string s;

map < string, bool > used;

priority_queue < pair < ld, vi > > heap;

vector < string > res;

vi temp;

string kq = "";

void back_track(int pos) {
	if (res.size() >= n) return ;
	bool ok = 1;
	for (int i = 0; i < 26; i++) if (temp[i] > 0) {
		ok = 0;
		string pre = kq;
		kq += (char)(i + 'A');
		temp[i] --;
		back_track(pos + 1);
		temp[i] ++;
		kq = pre;
	}
	if (ok && !used[kq]) {
		used[kq] = 1;
		res.pb(kq);
		return ;
	}
}

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0);
	for (int i = 0; i <= 100; i++) C[0][i] = 0;
	for (int i = 1; i <= 100; i++) {
		ld rem = __lg(1);
		for (int j = 1; j <= i; j++) rem += __lg(j);
		for (int j = i; j <= 100; j++) {
			ld &res = C[i][j]; res = -rem;
			for (int k = j; k >= j - i + 1; k--) res += __lg(k);
		}
	}
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> s;
		for (auto c : s) cnt[i][c - 'A'] ++;
	}
	used[""] = 1;
	for (int i = 0; i < 26; i++) temp.pb(0);
	heap.push({1, temp});
	while (heap.size()) {
		temp = heap.top().se; heap.pop();
		back_track(1);
		if (res.size() >= n) break;
		for (int i = 0; i < 26; i++) {
			temp[i] ++;
			ld v = 0;
			bool ok = 0;
			for (int j = 1; j <= m; j++) {
				ld cur = 0;
				bool th = 1;
				for (int c = 0; c < 26; c++) {
					if (cnt[j][c] < temp[c]) {
						cur = 0;
						th = 0;
						break;
					}
					cur += C[temp[c]][cnt[j][c]];
				}
				ok |= th;
				v += cur;
			}
			if (!ok) continue;
			// cout << i << " " << v << '\n';
			heap.push({v, temp});
			temp[i] --;
		}
	}
	for (auto x : res) cout << x << '\n';
}
