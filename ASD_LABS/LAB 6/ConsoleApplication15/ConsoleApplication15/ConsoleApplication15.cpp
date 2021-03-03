#include <stdio.h>
#define x 0.9


float pow(float n, int m) {
	float result = 1;
	for (int c = 0; c < m; c++) {
		result *= n;
	}
	return result;
}

float RecurseSum(float prevF, float* sum, int* i) {
	if (*i > 1) {
		*i -= 1;
		prevF = RecurseSum(prevF, sum, i);
	}
	*i += 1;
	*sum += prevF;
	prevF = prevF * (2 * *i - 1) * pow((x-1),2) / ((2 * *i + 1) * pow((x + 1),2));
	return prevF;
}
int main()
{
	float F = (x-1)/(x+1);
	int i;
	float sum = 0;
	printf_s("Enter you number: \n");
	scanf_s("%d", &i);
	F = RecurseSum(F, &sum, &i);
	printf_s("Sum  =  %f \n", sum * -1);
}

