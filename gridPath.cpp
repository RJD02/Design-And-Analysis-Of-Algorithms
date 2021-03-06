#include<bits/stdc++.h>
using namespace std;

int numberOfPaths(int m, int n) {
	int count[m][n];
	for(int i = 0; i < m; i++) {
		count[i][0] = 1;
	}
	for(int i = 0; i < n; i++) {
		count[0][i] = 1;
	}
	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			count[i][j] = count[i - 1][j] + count[i][j - 1];
			cout << count[i][j] << " ";
		}
		cout << endl;
	}
	return count[m - 1][n - 1];
}

int main() {
	int m, n;
	cin >> m >> n;
	cout << numberOfPaths(m, n);
	return 0;
}
