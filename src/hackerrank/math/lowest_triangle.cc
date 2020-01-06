#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int lowestTriangle(int base, int area) {
	return ceil((float)(2 * area) / base);
}

int main() {
	int base;
	int area;
	cin >> base >> area;
	int height = lowestTriangle(base, area);
	cout << height << endl;
	return 0;
}
