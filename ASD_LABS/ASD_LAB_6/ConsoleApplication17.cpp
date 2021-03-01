#include <stdio.h>
#include<math.h>
#define x 0.9

int main()
{
	float sum = (x - 1)/(x + 1);
	float F = (x - 1)/(x + 1);
	int num;
	printf_s("Enter number: ");
	scanf_s("%d", &num);
	printf_s("F%d = %.8lf\n", 1, F * -1);
	for (int i = 2; i <= num; i++) {
		F = F * (2 * i - 1) * (pow(x - 1, 2)) / ((2*i+1)*(pow(x+1, 2)));
		printf_s("F%d = %.8lf\n", i, F * -1);
		sum += F;
	
	}

	printf_s("Sum = %.8lf\n", sum*-1);
}



