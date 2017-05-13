#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	char period[2];
	unsigned int time[3];
	int result = -1;
	if (scanf("%2u:%2u:%2u%2s",&time[0], &time[1], &time[2], period) == 4
			&& isgreaterequal(time[0],1) && islessequal(time[0],12)
			&& isgreaterequal(time[1],0) && islessequal(time[2],59)){
		string p(period);
		if (p == "PM"){
			time[0] += (time[0] != 12 ? 12 : 0);
		} else {
			time[0] = (time[0] == 12 ? 0 : time[0]);
		}
		cout << setw(2) << setfill('0') << time[0]
			<< ":" << setw(2) << setfill('0') << time[1]
			<< ":" << setw(2) << setfill('0') << time[2];
		return 0;
	}
	return result;
}
