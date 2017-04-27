#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_point_valid(int p)
{
	return -100 <= p <= 100;
}

int main(int argc, char** argv)
{
	// read input
	unsigned int n;
	cin >> n;
	if (n < 1 && n > 15)
		return -1;
	while (n--) {
		int px, py, qx, qy;
		cin >> px >> py >> qx >> qy;
		if (!is_point_valid(px) && !is_point_valid(py)
			&& !is_point_valid(qx) && !is_point_valid(qy)) {
			return -1;
		}
		cout << qx*2 - px << " " << qy*2 - py << endl;
	}
}
