#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned int t;
	cin >> t;
	if (t < 1 && t > 1000)
		return -1;
	while (t--) {
		unsigned int n;
		cin >> n;
		if (n > pow(10, 6))
			return -1;
		cout << n + 1 << endl;
	}
}
