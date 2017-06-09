#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	unsigned int n; unsigned int d;
	cin >> n >> d;
	if (!(1 <= n <= pow(10, 5) && 1 <= d <= n))
		return -1;
	vector<unsigned int> arr;
	while (n-- > 0) {
		unsigned int a;
		cin >> a;
		if (!(1 <= a <= pow(10,6)))
			return -1;
		arr.push_back(a);
	}
	while (d-- > 0){
		unsigned int front = arr.front();
		auto first = arr.begin();
		while (first != arr.end()-2){
			*first = *(first+1);
			first++;
		}
		arr[arr.size()-2] = arr.back();
		arr[arr.size()-1] = front;
	}
	for_each(arr.begin(), arr.end(), [] (unsigned int i) {
			cout << i << " ";
			});
	cout << endl;
}

