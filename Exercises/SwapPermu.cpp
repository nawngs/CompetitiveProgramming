#include <bits/stdc++.h>

using namespace std;

int t, n, a[100005], pos[100005];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	int pre = 0;
	for (int i = 1; i <= n; i++) {
		if (pos[i] <= pre) continue;
		if (pos[i] == n) {
			//for (int j = 1; j <= n; j++) cout << a[j] << '\n'
			//cout << pre << '\n';
			for (int j = 1; j < pos[i] - pre; j++) {
				//cout << a[pre + j]  << " " << i + j << '\n';
				if (a[pre + j] != i + j) {
					cout << "No" << '\n';
					return ;
				}
			}
			for (int j = pos[i] - 1; j > pre; j--) {
				pos[a[j]] = j + 1;
				pos[a[j + 1]] = j;
				swap(a[j], a[j + 1]);
			}
			pre = n;
		}
		else {
			int tam = pos[i];
			for (int j = 1; j < pos[i] - pre - 1; j++) {
				if (a[pre + j] != i + j) {
					cout << "No" << '\n';
					return ;
				}
			}
			for (int j = pos[i] - 1; j > pre; j--) {
				pos[a[j]] = j + 1;
				pos[a[j + 1]] = j;
				swap(a[j], a[j + 1]);
			}
			//cout << tam << '\n';
			pre = tam - 1;
		}
	}
	cout << "Yes" << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> t;
	while (t --) sol();
}