#include <stdio.h>;
#include <math.h>;
int main()
{
	int n;
	int counter1 = 0;
	double counter = 1;
	double S = 0;
	printf(" Write n : ");
	scanf_s(" % d & " , &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			counter *= ((j + 1) * sin(j));
		}
		S += i * (i + 1) / counter;
		counter = 1;
		counter1 += 4 * i + 4;
	}
	printf("counter1: ");
	printf(" % d & " , counter1);
	printf("\n");
	printf("result: ");
	printf(" % lf & ", S);
	return 0;
}