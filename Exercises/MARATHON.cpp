#include <bits/stdc++.h>

using namespace std;

int a[5], k;

int main(){
	cin >> a[1] >> a[2] >> a[3] >> k;
	sort(a + 1, a + 4);
	cout << max(0, a[1] - a[2] + k) + max(0, a[2] + k - a[3]);
}