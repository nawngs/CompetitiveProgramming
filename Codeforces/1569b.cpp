#include <bits/stdc++.h>

using namespace std;

int t;

void sol() {
	int n;
	string s;
	cin >> n >> s;
	deque < int > tam;
	char ans[55][55];
	s = ' ' + s;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) ans[i][j] = 'a';

	for (int i = 1; i <= n; i++) {
		if (s[i] == '2') tam.push_back(i); 
	}
	if (tam.size() == 1 || tam.size() == 2) {
		cout << "NO" << '\n';
		return ;
	}
	int temp = tam.front();
	tam.pop_front();
	tam.push_back(temp);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					ans[i][j] = 'X';
					continue;
				}
				if (s[j] == '1') ans[i][j] = ans[j][i] = '=';
				else {
					ans[i][j] = '+';
					ans[j][i] = '-';
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (s[i] == '2') {
			temp = tam.front();
			tam.pop_front();
			ans[i][temp] = '+';
			ans[temp][i] = '-';
		}
	}
	cout << "YES" << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) ans[i][j] = 'X';
			if (ans[i][j] == 'a') ans[i][j] = '=';
			cout << ans[i][j];
		}
		cout << '\n';
	}

}

int main() {
	cin >> t;
	while (t --) sol();	
}