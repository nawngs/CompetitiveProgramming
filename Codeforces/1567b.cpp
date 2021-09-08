#include <bits/stdc++.h>

using namespace std;

int t, f[300005];

bool getbit(int pos, int a){
	return (a & 1 << pos);
}

void sol() {
	int a, b, ans;
	cin >> a >> b;
	ans = a;
	int tam = f[a - 1];
	//cout << tam << '\n';
	if (tam == b) {
		cout << ans << '\n';
		return ;
	}
	if ((tam ^ a) == b) {
		cout << ans + 2 << '\n';
		return ;
	}
	cout << ans + 1 << '\n';
}

int main() {
	//cout << getbit(9, 512) << '\n';
	f[0] = 0;
	for (int i = 1; i <= 300000; i++) f[i] = f[i - 1] ^ i;
	cin >> t;
	while (t --) sol();
}