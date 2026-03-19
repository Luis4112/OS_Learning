#include <stdio.h>
#include <stdlib.h>
int main(){

	int a = 10;
	 int *p = malloc(sizeof(int));
	 *p = 10;
	printf("Size of variable: %d", *p);
	free(p);
	printf("Size after: %d", *p);
}
