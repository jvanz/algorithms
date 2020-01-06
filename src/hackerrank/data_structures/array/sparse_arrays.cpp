#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned int N;
	cin >> N;
	vector<string> strs;
	while (N--) {
		string s;
		cin >> s;
		strs.push_back(s);
	}
	unsigned int Q;
	cin >> Q;
	while (Q--) {
		string s;
		cin >> s;
		cout << count(strs.begin(), strs.end(), s) << endl;
	}
	return 0;
}
