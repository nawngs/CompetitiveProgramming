#include <bits/stdc++.h>

using namespace std;

int t;

void sol() {
	int n;
	string s;
	cin >> n >> s;
	int cnt[11], pos5 = -1;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		if (((s[i] - '0') % 2 == 0 && s[i] != '2') || (s[i] == '9') || (s[i] == '1')) {
			cout << 1 << '\n' << s[i] << '\n';
			return ;
		} 
		if (s[i] == '5' && i != 0) {
			pos5 = i;
		}
		cnt[s[i] - '0'] ++;
	}
	if (pos5 != -1) {
		cout << 2 << '\n' << s[pos5 - 1] << s[pos5] << '\n';
		return ;
	}
	for (int i = 1; i <= 9; i++) {
		if (cnt[i] >= 2) {
			cout << 2 << '\n' << i << i << '\n';
			return ;
		} 
	}
	int pos1 = -1, pos2 = -1;
	for (int i = 0; i < n; i++) {
		int tam = s[i] - '0';
		tam %= 3;
		//cout << tam
		if (tam == 1) pos1 = i;
		if (tam == 2) pos2 = i;
		if (pos1 != -1 && pos2 != -1) {
			cout << 2 << '\n' << s[min(pos1, pos2)] << s[max(pos1, pos2)] << '\n';
			return ;
		}
	}
}

int main() {
	cin >> t;
	while (t --) {
		sol();
	}
}