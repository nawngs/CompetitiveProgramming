//link: https://oj.vnoi.info/problem/fc075_fprime
#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e7;
int k, n;
bool f[nmax + 5];


void sang(){
	for(int i = 1; i <= nmax; i++) f[i] = true;
	f[0] = f[1] = false;
	for(int i = 2; i * i <= nmax; i++)
		if(f[i] == true) for(int j = i * i; j <= nmax; j += i) f[j] = false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	sang();
	cin >> n;
	//cout << f[2] << '\n';
	while(n --){
		cin >> k;
		if(k < 0) cout << "NO" << '\n';
		else{
			f[k] == true ? cout << "YES" << '\n' : cout << "NO" << '\n';
		}
	}
}
