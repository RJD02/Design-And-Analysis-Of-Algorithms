#include<bits/stdc++.h>
using namespace std;
// Function match returns the pair of the common string and the length of this string
pair<string, int> match(string s1, string s2) {
	if(s1.length() == 0 || s2.length() == 0)
		return make_pair("", 0);
	if(s1 == s2)
		return make_pair(s1, s1.length());
	int max_count = 0, curr_count = 0;
	string res = "", curr_str = "";
	for(int i = 0; i < s1.length(); i++) {
		for(int ii = 0; ii < s2.length(); ii++) {
			if(s1[i] == s2[ii]) {
				curr_count = 0;
				int start_s1 = i;
				int start_s2 = ii;
				curr_str = "";
				while(start_s2 < s2.length() && start_s1 < s1.length()) {
					if(s1[start_s1] != s2[start_s2])
						break;
					curr_count++;
					curr_str += s1[start_s1];
					start_s1++;
					start_s2++;
				}
			}
			max_count = max(curr_count, max_count);
			// res = max(res, curr_str);
			if(res.length() < curr_str.length())
				res = curr_str;
		}
	}
	return make_pair(res, max_count);
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	pair<string, int> p = match(s1, s2);
	cout << p.first << " " << p.second;
	return 0;
}
