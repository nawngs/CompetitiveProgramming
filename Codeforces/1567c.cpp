#include <bits/stdc++.h>
 
using namespace std;
 
int f[22], t;
 
bool getbit(int pos, int a){
	return (a & 1 << pos);
}
 
void build_f() {
	for (int i = 0; i <= 18; i++) {
		for (int j = 0; j <= 9; j++) if (i - j >= 0 && i - j <= 9) f[i] ++;
		//cout << i << " " << f[i] << '\n';
	}
}
 
void sol() {
	string s;
	cin >> s;
	long long ans = 0;
	int n = s.size();
	for (int i = 0; i <= (1 << (n - 1)); i++) {
		if (getbit(n - 1, i)) continue;
		if (n - 2 >= 0 && getbit(n - 2, i)) continue;
		int tam = 1;
		for (int j = n - 1; j >= 0; j --) {
			if (getbit(j, i) && s[j] == '0') {
				if (j < 2 || !getbit(j - 2, i)) {
					tam = 0;
					break;
				}
				tam *= f[9];
				continue;
			}
			if (j < 2) {
				//cout << s[j] - '0' - getbit(j, i) << '\n';
				tam *= f[s[j] - '0' - getbit(j, i)];
			}
			else {
				//cout << s[j] - '0' - getbit(j, i) + 10 * getbit(j - 2, i) << '\n';
				tam *= f[s[j] - '0' - getbit(j, i) + 10 * getbit(j - 2, i)];
			}
		}
		//cout << i << " " << tam << '\n';
		ans += tam;
	}
	cout << ans - 2 << '\n';
}
 
int main() {
	build_f();
	cin >> t;
	while (t --) {
		sol();
	}
}