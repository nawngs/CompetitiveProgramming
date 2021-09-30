#include <bits/stdc++.h>

using namespace std;

int t;

string change_str(int x) {
	vector < int > a;
	while (x > 0) {
		a.push_back(x % 10);
		x /= 10;
	}
	reverse(a.begin(), a.end());
	string ans = "";
	for (int i = 0; i < a.size(); i++) ans += a[i] + '0';
	return ans;
}

void sol() {
	int x;
	cin >> x;
	int i = 0;
	int cnt = 0;
	string temp = "";
	while (1) {
		i ++;
		temp += change_str(i);
		int tam = temp.size();
		if (cnt + tam < x) {
			cnt += tam;
			continue;
		} 
		if (cnt + tam >= x) {
			cout << temp[x - cnt - 1] << '\n';
			return ;
		}
	}
}

int main() {
	cin >> t;
	while (t --) sol();
}