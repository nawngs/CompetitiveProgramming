//link: https://codeforces.com/problemset/problem/1547/A
#include <bits/stdc++.h>

using namespace std;

int ntest;

int main(){
	cin >> ntest;
	while(ntest --){
		int xa, ya, xb, yb, xf, yf;
		cin >> xa >> ya >> xb >> yb >> xf >> yf;
		cout << abs(xa - xb) + abs(ya - yb) + 2 * (xa == xb && xa == xf && min(ya, yb) <= yf && yf <= max(ya, yb)) + 2 * (ya == yb && ya == yf && min(xa, xb) <= xf && xf <= max(xa, xb)) << '\n';
		continue;
	}
}