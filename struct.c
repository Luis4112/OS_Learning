#include <stdio.h>
#include <string.h>
struct Mystructure {
	int myNum;
	char name[50]; 
};

int main() {
	struct Mystructure s1;
	s1.myNum = 20;
	strcpy(s1.name, "John");
	printf("My name is: %s\n", s1.name);
	printf("My age is : %d\n", s1.myNum);
	struct Mystructure *ptr = &s1;
	ptr ->myNum;
	printf("ptr returns: %d\n", ptr->myNum);
	return 0;
}


