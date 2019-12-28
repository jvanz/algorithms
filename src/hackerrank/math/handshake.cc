#include <cmath>
#include <iostream>

using namespace std;


int main(){
	int T;
	cin >> T;
	if (T < 1 || T > 1000){
		cout << "Invalid T" << endl;
		return -1;
	}
	while (T--){
		int N;
		cin >> N;
		if (N <= 0 || N >= pow(10,6)){
			cout << "Invalid N" << endl;
			return -1;
		}
		cout << (N * (N-1)) / 2 << endl;
	}
	return 0;
}
