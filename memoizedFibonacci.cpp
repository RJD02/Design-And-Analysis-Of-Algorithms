#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int N;
vector<int> dp(100, -2);

int fibo(int n) {
	if(n == 0 || n == 1)
		return n;
	return fibo(n - 1) + fibo(n - 2);
}

int fib(int n) {
	if(dp[n] != -2)
		return dp[n];
	if(n == 0 || n == 1)
		return n;
	dp[n] = fib(n - 1) + fib(n - 2);
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cout << fib(N) << endl;
	// cout << fibo(N);
	return 0;
}
