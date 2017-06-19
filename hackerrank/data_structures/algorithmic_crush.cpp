#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	unsigned int N, M;
	cin >> N >> M;
	vector<unsigned int> arr(N);
	unsigned int max = 0;
	while (M--){
		unsigned int a, b, k;
		cin >> a >> b >> k;
		a--; b--; // array is 0 index
		for (; a <= b; a++){
			arr[a] += k;
			if (arr[a] > max)
				max = arr[a];
		}
	}
	cout << max << endl;
}
