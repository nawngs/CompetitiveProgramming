#include <bits/stdc++.h>

using namespace std;

int n, a[2005], b[2005], c[2005];

bool check (int l, int r) {
	vector < int > val_l, val_r;
	val_l.clear();
	val_r.clear();
	val_l.push_back(a[l]);
	val_l.push_back(b[l]);
	val_l.push_back(c[l]);
	val_r.push_back(a[r]);
	val_r.push_back(b[r]);
	val_r.push_back(c[r]);
	sort(val_l.begin(), val_l.end());
	sort(val_r.begin(), val_r.end());
	//cout << val_l.size(); 
	if (val_l[1] == val_l[0]) {
		val_l[1] ++;
		val_l[0] = -1;
	}
	if (val_l[2] == val_l[1]) {
		val_l[2] ++;
		val_l[1] = -1;
	}
	if (val_r[1] == val_r[0]) {
		val_r[1] ++;
		val_r[0] = -1;
	}
	if (val_r[2] == val_r[1]) {
		val_r[2] ++;
		val_r[1] = -1;
	}
	sort(val_l.begin(), val_l.end());
	sort(val_r.begin(), val_r.end());
	for (int i = 2; i >= 0; i --) {
		//cout << i << '\n';
		if (val_l[i] > val_r[i]) return true;
		if (val_l[i] < val_r[i]) return false;
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j >= 1; j --) {
			//cout << i << " " << j << '\n';
			if (check(j, i)) ans ++;
		}
	}
	cout << ans;
}