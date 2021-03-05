#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
	int fib_table[n];
	fib_table[0] = 0;
	fib_table[1] = 1;
	for(int i = 2; i <= n; i++) {
		fib_table[i] = fib_table[i - 1] + fib_table[i - 2];
	}
	return fib_table[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	cout << fib(n);
	return 0;
}
