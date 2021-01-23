#include <iostream>


/* Variant 1*/
int main()
{
	float x;
	float y;
	printf("Enter x : ");
	scanf_s("%f", &x);
	if (x >= 0) {
		if (x <= 8) {
			y = (-3 * x * x) / 5 + 9;
			printf("Answer: %f", y);
		}
		else if (x >= 16) {
			y = (-3 * x * x) / 5 + 9;
			printf("Answer: %f", y);
		}
	}
	else if (x < -1) {
		y = 15 * x - 2;
		printf("%f", y);
	}
	else printf("no result\n");
	return 0;

}

/* Variant 2*/
#include <stdio.h>
#include <math.h>

int main()
{
	float x;
	float y;
	printf("Enter x: ");
	scanf_s("%f", &x);

	if ((x >= 0) && (x <= 8) || (x >= 16))
	{
		y = (-3 * x * x) / 5 + 9;
		printf("Answer : %f\n", y);
	}
	else if ((x < -1))
	{
		y = 15 * x - 2;
		printf("Answer : %f\n", y);
	}
	else
	{
		printf("no results\n");
	}
	return 0;
}


