//link:https://oj.vnoi.info/problem/fcb034_height
#include <bits/stdc++.h>

using namespace std;

int t, n, a[100005], res[100005];

void sol() {
	cin >> n;
	memset(res, 1, sizeof(res));
	for (int i = 1; i <= n; i++) cin >> a[i];
	stack < int > st;
	a[n + 1] = 1e9 + 7;
	for (int i = 1; i <= n + 1; i++) {
		//cout << i << " " << st.top() << '\n';
		if (st.size() && a[i] > st.top()) {
			int val = a[st.top()];
			int cnt = res[st.top()];
			st.pop();
			while (st.size() && st.top() < a[i]) {
				if (a[st.top()] == val) {
					res[st.top()] = cnt;
				}
				else {
					val = a[st.top()];
					cnt = res[st.top()];
				}
				st.pop();
			}
		}
		if (st.size() && a[i] == a[st.top()]) res[i] = res[st.top()] + 1;
		else res[i] = 0;
		st.push(i);
	}
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	cout << '\n';
}

int main() {
	cin >> t;
	while (t --) sol();
}