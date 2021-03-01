#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void selectActivities(vector<int> s, vector<int> f) {
	vector<pair<int, int>> ans;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
	for(int i = 0; i < s.size(); i++) {
		p.push(make_pair(f[i], s[i]));
	}
	auto it = p.top();
	int start = it.second;
	int end = it.first;
	p.pop();
	ans.push_back(make_pair(start, end));

	while(!p.empty()) {
		auto itr = p.top();
		p.pop();
		if(itr.second >= end) {
			start = itr.second;
			end = itr.first;
			ans.push_back(make_pair(start, end));
		}
	}
	cout << "Following Activities should be selected" << endl;
	for(auto itr = ans.begin(); itr != ans.end(); itr++) {
		cout << itr -> first << " " << itr -> second << endl;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> s(n);
	vector<int> f(n);
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> f[i];
	}
	selectActivities(s, f);
	return 0;
}
