#include <stdio.h>
#include <stdlib.h>

long int Fact(long int n);
long int Fib(long int n);


int main(){
	
	printf("Fact: %ld\n", Fact(4));
	
	printf("Fib: %ld\n", Fib(6));
	
	return 0;
}

long int Fact(long int n){
	if (n == 0)
		return 1;
	else
		return n * Fact(n -1);
}

long int Fib(long int n){
	if(n == 1 || n == 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
