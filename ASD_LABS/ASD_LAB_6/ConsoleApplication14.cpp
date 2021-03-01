#include <stdio.h>
#include <math.h>
#define x 0.5


float RecurseSum(int length, float prevF, float sum, int i) {
	i++;
	prevF = prevF * (2 * i - 1)* pow((x-1), 2) / ((2 * i + 1) * pow((x + 1), 2));
	sum += prevF;
	if (length + 1 != i) {
		sum = RecurseSum(length, prevF, sum, i);
	}
	return sum;
}
int main()
{
	float F = (x-1)/(x+1);
	int input;
	float sum = (x-1)/(x+1);
	printf_s("Enter your number: \n");
	scanf_s("%d", &input);
	sum = RecurseSum(input, F, sum, 1);
	printf_s("Sum =  %f \n", sum * -1);
}