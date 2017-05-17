#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	unsigned int n, m;
	cin >> n >> m;
	if (n <= 1000 && m <= 1000){
		if (n % 2 == 0 && m % 2 == 0){
			cout << (n * m) / 4 << endl;
		} else {
			unsigned int supply = 0;
			if (m % 2 != 0){
				m -= 1;
				supply += ceil(n / 2);
				if (n % 2 != 0)
					supply += ceil(m / 2);
			} else if (n % 2 != 0) {
				supply += ceil(m / 2);
				n -= 1;
			}
			supply += ((n * m) / 4);
			cout << supply << endl;
		}
		return 0;
	}
	return -1;
}
