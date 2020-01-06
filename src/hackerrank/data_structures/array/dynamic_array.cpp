#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned int N, Q;
	cin >> N >> Q;
	int lastAnswer = 0;
	vector<vector<int>> seqList(N);
	while (Q--) {
		unsigned int type;
		cin >> type;
		if (type == 1 || type == 2) {
			unsigned int x, y;
			cin >> x >> y;
			auto index = (x ^ lastAnswer) % N;
			if (type == 1) {
				seqList[index].push_back(y);
			} else {
				lastAnswer =
				    seqList[index][y % seqList[index].size()];
				cout << lastAnswer << endl;
			}
		} else {
			return -1;
		}
	}
	return 0;
}
