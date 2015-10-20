
#include <stdio.h>

void insertion_sort(int[], int);
void print_int_arr(const int[], int);

int main(int argc, char ** argv){
	int numbers[] = {5,2,10,4,7,1,9,3,6,8};
	int length = sizeof(numbers) / sizeof(numbers)[0];
	printf("unsorted array: ");
	print_int_arr(numbers, length);
	insertion_sort(numbers, length);
	printf("sorted array: ");
	print_int_arr(numbers, length);
}

void insertion_sort(int numbers[], int length){
	int j;
	for(j = 1; j < length; j++ ){
		int key = numbers[j];
		int i = j - 1;
		while(i >= 0 && numbers[i] > key){
			numbers[i + 1] = numbers[i];
			i = i - 1;
		}
		numbers[i + 1] = key;
	}
}

void print_int_arr(const int numbers[], int length){
	int i;
	for(i=0;i < length; i++) {
		printf("%d%s", numbers[i], i < length-1? ",": "");
	}
	printf("\n", numbers[i]);
}
