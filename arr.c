#include <stdio.h>

int main () {
	int arr[3] = {10,20,30};
	int *p = arr;
	printf( "bracket: %d\n", arr[2]);
	printf("pointer: %d\n", *(p + 2));
	printf ("comparison: %d\n", arr[2] == *(p + 2));
	return 0;
}
