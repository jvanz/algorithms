#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	unsigned int n, m;
	cin >> n >> m;
	if (n <= 1000 && m <= 1000)
		cout << ((n+1)/2)*((m+1)/2) << endl;
}
