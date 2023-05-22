//link: https://oj.vnoi.info/problem/fc070_function

#include <bits/stdc++.h>

using namespace std;

long long n, chan, le;

int main(){
	cin >> n;
	chan = n - (n % 2 == 1);
	le  = n - (n % 2 == 0);
	cout << ((chan + 2) * ((chan - 2) / 2 + 1) - (le + 1) * ((le - 1) / 2 + 1)) / 2;
}