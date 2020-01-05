#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	unsigned int n; unsigned int d;
	cin >> n >> d;
	if (!((1 <= n) && (n <= pow(10, 5)) && (1 <= d) && (d <= n)))
		return -1;
	vector<unsigned int> arr;
	while (n-- > 0) {
		unsigned int a;
		cin >> a;
		if (!((1 <= a) && (a <= pow(10,6))))
			return -1;
		arr.push_back(a);
	}
	for (unsigned int i = 0; i < d; i++){
		if (i < arr.size())
			arr.push_back(arr[i]);
		else
			arr.push_back(arr[i +(arr.size()-i)]);
	}
	for (unsigned int i = 0; i < arr.size()-d; i++){
		arr[i] = arr[i+d];
	}
	for_each(arr.begin(), arr.end()-d, [] (unsigned int i) {
			cout << i << " ";
			});
	cout << endl;
}

