#include <stdio.h>

int main() {

	int a = 2;
 	int *p = &a;
	*p = 10;
	printf("%d", a);

}
