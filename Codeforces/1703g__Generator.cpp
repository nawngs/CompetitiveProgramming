#include <bits/stdc++.h>

using namespace std;

const int NTEST = 10; //so luong test
const string TESTNAME = "TASK"; // ten bai

long long get_random(long long l, long long h) {
    return l + rand() % (h - l + 1);
}

// get random(l , r) lay 1 so bat ki tu l den r

void make_test(){
	int n = get_random(40, 50), k = get_random(1, 1e9);
	cout << n << " " << k << '\n';
	for (int i = 1; i <= n; i++) {
		cout << get_random(1, 1e9) << ' ';
	}
	cout << '\n';
}

int main(){
	string fout = TESTNAME + ".inp"; //fout = "TASK.INP"
	//freopen(fout.c_str(), "w", stdout); //tao file .INP co input
	srand(time(NULL)); // tranh lap test
	cout << NTEST << '\n';
	for(int test = 1; test <= NTEST; test ++){
		make_test();
	}
}

