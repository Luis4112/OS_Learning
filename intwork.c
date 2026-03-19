#include <stdio.h>

int Myfunction(int a, int b){
	return a + b;


}

int main(){
	int result = Myfunction(1,2);
	printf("The result is %d", result);
	return 0;
}
