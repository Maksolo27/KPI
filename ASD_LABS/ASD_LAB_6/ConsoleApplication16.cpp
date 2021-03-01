#include <stdio.h>
#include<math.h>
#define x 0.9

float RecurseSum(int length, float prevF, float sum, int i) {
	float tempF = prevF;
	if (length  > i) {
		i++;
		prevF = prevF * (2 * i - 1) * pow((x - 1), 2) / ((2 * i + 1) * pow((x + 1), 2));
		sum = RecurseSum(length, prevF, sum, i);
	}
	sum += tempF;
	return sum;
}
int main()
{
	float F = (x-1)/(x+1);
	int input;
	float sum = 0;
	printf_s("Enter number: \n");
	scanf_s("%d", &input);
	sum = RecurseSum(input, F, sum, 1);
	printf_s("Sum =  %f \n", sum*-1);
}





