#include <stdio.h>
#define K 10

int matrix[K][K] =
{
  { 2, 3, 7, -8, -2, 0, 12, 3, 5, 9 },
  { 1, -6, 0, 2, 9, 6, 5, 4, 9, 12 },
  { 2, 15, -3, 7, 14, 7, 2, 8, 16, 4 },
  { 100, 56, -2, 44, 12, 4, 7, 18, 101, 17 },
  { 14, 2, 1, 3, 9, 6, 2, 4, 17, 5 },
  { 23, 9, 2, 3, 5, 22, 0, 5, 7, 1 },
  { 12, 22, 1, 23, 0, -4, 3, 14, 12, -2 },
  { 54, 23, 72, 0, 2, 15, 1, 34, 0, 5 },
  { -23, 13, 0, 0, 0, 0, 222, 22, 0, -14 },
  { 1, 1, 4, 3, 6, 2, 4, 5, 14, 99 }
};

void print(int A[][10], int N, int M)
{
    for (int R = 0; R < N; R++) {
        for (int C = 0; C < M; C++)
            printf_s("%d  ", A[R][C]);
        printf_s("\n");
    }
}

void hoarasort(int a[][K], int first, int last, int lines) {
    int L, R, T, temp;

    if (first < last) {
        T = first;
        L = first;
        R = last;
        while (L < R) {
            while (a[lines][L] <= a[lines][T] && L < last)
                L++;
            while (a[lines][R] > a[lines][T])
                R--;
            if (L < R) {
                temp = a[lines][L];
                a[lines][L] = a[lines][R];
                a[lines][R] = temp;
            }
        }
        temp = a[lines][T];
        a[lines][T] = a[lines][R];
        a[lines][R] = temp;
        hoarasort(a, first, R - 1, lines);
        hoarasort(a, R + 1, last, lines);
    }
}

void myquicksort() {
    for (int line = 0; line < K; line++) {
        hoarasort(matrix, 0, K, line);
    }
}
int main()
{
    print(matrix, K, K);
    myquicksort();
    printf("\n");
    print(matrix, K, K);
    return 1;
}
