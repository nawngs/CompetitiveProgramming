#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const int NMAX = 1E5;	
const int BLOCK = 320;
const int INF = 1E9 + 7;

int n, q, a[NMAX + 3], chg[NMAX / BLOCK + 5];

pii jump[NMAX + 3];

void upd(int l, int r) {
	stack < int > st;
	for (int i = min(n, (r + 1) * BLOCK - 1); i >= min(n + 1, r * BLOCK); i--) {
		while (st.size() && a[st.top()] <= a[i]) st.pop();
		st.push(i);
	}
	for (int i = min(n, r * BLOCK - 1); i >= max(1, l * BLOCK); i--) {
		while (st.size() && a[st.top()] + chg[st.top() / BLOCK] <= a[i] + chg[i / BLOCK]) st.pop();
		if (st.empty() || st.top() - i > 100) jump[i] = {INF, INF}; 
		else {
			if (st.top() / BLOCK != i / BLOCK) jump[i] = {1, st.top()};
			else jump[i] = jump[st.top()], jump[i].fi ++;
		}
		st.push(i);
	} 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int i, k; cin >> i >> k;
			for (int j = i + 1; j <= n; j++) if (k && a[j] > a[i] && j - i <= 100) i = j, k--;
			cout << i << '\n';
		}
		else {
			int l, r, d; cin >> l >> r >> d;
			for (int i = l; i <= r; i++) a[i] += d;
		}
	}
}