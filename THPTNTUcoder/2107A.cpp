#include <bits/stdc++.h>

using namespace std;

int n;
char a[1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	int cnt = 0;
	a[0] = 'Z';
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == a[i - 1]) cnt ++;
	}
	cout << cnt;
}