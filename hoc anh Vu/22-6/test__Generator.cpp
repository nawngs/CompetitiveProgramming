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
}

int main(){
	srand(time(NULL));
	int n = get_random(2, 10);
	int m = get_random(1, n - 1);
	cout << n << " " << m << '\n';
	for (int i = 1; i <= n; i++) {
		cout << get_random(1, 1000) << " " << get_random(1, 20) << '\n';
	}
}

