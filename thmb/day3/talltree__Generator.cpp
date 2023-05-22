#include <bits/stdc++.h>

using namespace std;

const int NTEST = 10; //so luong test
const string TESTNAME = "TASK"; // ten bai

long long get_random(long long l, long long h) {
    return l + rand() % (h - l + 1);
}

// get random(l , r) lay 1 so bat ki tu l den r

void make_test(){
	/*
	nhap input
	vd tao inp co n va day a[n]
	code:
	int n = get_random(l, r);
	for(int i = 1; i <= n; i++){
		int x;
		x = get_random(l, r);
		cout << x;
	}
	*/
	cout << get_random(1, 4) << '\n';
	int n = get_random(1, 10);
	cout << n << '\n';
	for (int i = 2; i <= n; i++) cout << get_random(1, i - 1) << ' ';
	cout << '\n';
	int q = get_random(1, 10);
	cout << q << '\n';
	while (q--) {
		int type = get_random(1, 3);
		if (type == 1) cout << "add" << " " << get_random(1, n) << " " << get_random(-100, 100) << " " << get_random(-100, 100) << '\n';
		else if (type == 2) cout << "get" << " " << get_random(1, n) << '\n';
		else cout << "sum" << " " << get_random(1, n) << '\n';
	}
}

int main(){
	srand(time(NULL));
	make_test();
}

