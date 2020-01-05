#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	unsigned int N, M;
	cin >> N >> M;
	if ((N < 3 || N > pow(10, 7)) || M > (2 * pow(10,5)))
		return -1;

	vector<long> arr(N);
	long max = 0;
	while (M--){
		unsigned int a, b, k;
		cin >> a >> b >> k;
		if ( a > b || a > N || b > N)
			return -1;
		a--; b--; //  array is 0 index
		arr[a] += k;
		if ((b+1) <= N)
			arr[b+1] -= k;
	}
	long x = 0;
	for (unsigned int i = 0; i < N; i++){
		x = x + arr[i];
		if (max < x)
			max = x;
	}
	cout << max << endl;
}
