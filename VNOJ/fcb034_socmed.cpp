#include <bits/stdc++.h>

using namespace std;

int n, k, res[105];

string user[105], pass[105];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> user[i] >> pass[i];
	cin >> k;
	for (int i = 1; i <= k; i++) {
		string a, b;
		cin >> a >> b;
		for (int j = 1; j <= n; j++) if (a == user[j] && b == pass[j]) res[j] ++;
	}
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
}