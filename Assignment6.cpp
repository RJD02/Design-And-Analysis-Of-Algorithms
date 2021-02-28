#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, p, f;
	int count = 0;
	cin >> n >> p >> f;
	// int morning[n], evening[n];
	vector<int> morning(n), evening(n);
	for(int i = 0; i < n; i++) {
		cin >> morning[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> evening[i];
	}
	sort(morning.begin(), morning.end());
	sort(evening.rbegin(), evening.rend());
	for(int i = 0; i < n; i++) {
		if(morning[i] + evening[i] > p) {
			count += morning[i] + evening[i] - p;
		}
	}
	cout << count * f;
	return 0;
}
