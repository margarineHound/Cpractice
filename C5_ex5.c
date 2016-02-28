#include <stdio.h>

int maximum(int x, int y, int z);
int main(int argc, char const *argv[])
{
	int number1;
	int number2;
	int number3;

	printf("Enter Three Integers: ");
	scanf("%d%d%d", &number1, &number2, &number3);

	printf("Maximum is %d\n ", maximum(number3, number2, number1));

	return 0;
}

int maximum(int x, int y, int z)
{
	if(y>x && y> z)
		return y;
	else if(z>x && z> y)
		return z;
	else return x;
}