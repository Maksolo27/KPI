#include <stdio.h>
#include <math.h>
#define x 0.1

float RecurseSum(float prevF, float* sum, int* i) {
	if (*i > 1) {
		*i -= 1;
		prevF = RecurseSum(prevF, sum, i);
	}
	*i += 1;
	*sum += prevF;
	prevF = prevF * (2 * *i - 1) * powf((x-1),2) / ((2 * *i + 1) * powf((x + 1),2));
	return prevF;
}
int main()
{
	float F = (x-1)/(x+1);
	int i;
	float sum = 0;
	printf_s("Please, input your integer number\n");
	scanf_s("%d", &i);
	F = RecurseSum(F, &sum, &i);
	printf_s("Sum of range equal: ( %f )\n", sum);
}

