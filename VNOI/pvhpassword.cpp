//link: https://oj.vnoi.info/problem/pvhpassword
#include <bits/stdc++.h>

using namespace std;

string s;
int a[27], n;
long long ans = 0;

int main(){
	cin >> s >> n;
	a[1] = n;
	for(int i = 2; i <= 26; i++) a[i] = (a[i - 1] + 1) % 26;
	for(int i = 0; i < s.size(); i++) ans += a[s[i] - 'a' + 1];
	cout << ans;
}