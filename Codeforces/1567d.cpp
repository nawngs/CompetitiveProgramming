#include <bits/stdc++.h>

using namespace std;

int t, s, n, mu10[12];

void sol() {
	cin >> s >> n;
	vector < int > res, digit;
	res.resize(n + 3, 0);
	int cur_s = s;
	int invalid = n;
	while (s > 0) {
		digit.push_back(s % 10);
		s /= 10;
	}
	for (int i = digit.size() - 1; i >= 0; i--) {
		int j = invalid <= 0 ? 1 : n - invalid + 1;
		while (cur_s >= mu10[i]) {
			if (cur_s - mu10[i] >= invalid - 1) {
				res[j] += mu10[i];
				cur_s -= mu10[i];
				invalid --;
			}
			else break;
			if (j == n) j = 0;
			++ j;
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	cout << '\n';
}

int main() {
	mu10[0] = 1;
	for (int i = 1; i <= 9; i++) mu10[i] = mu10[i - 1] * 10;
	cin >> t;
	while (t --) sol();
}