#include <stdio.h>
#include<math.h>
#define x 0.1



int main()
{
	float F = (x - 1) / (x + 1);
	float sum = F;
	int input;
	printf_s("Please, input your integer number\n");
	scanf_s("%d", &input);
	for (int i = 2; i <= input; i++) {
		F = F * (2 * i - 1) * powf((x - 1), 2) / ((2 * i + 1) * powf((x + 1), 2));
		sum += F;
	}
	printf_s("Sum of range equal: ( %f )\n", sum);
}

//F* (2 * i - 1)* powf((x - 1), 2) / ((2 * i + 1) * powf((x + 1), 2))


