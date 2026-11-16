#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_N 100

void print_array(const int a[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}

int checked_multiply(long long a, long long b, long long *result)
{
    if (a == 0 || b == 0) {
        *result = 0;
        return 1;
    }

    if (a == -1 && b == LLONG_MIN) return 0;
    if (b == -1 && a == LLONG_MIN) return 0;

    if (a > 0) {
        if (b > 0 && a > LLONG_MAX / b) return 0;
        if (b < 0 && b < LLONG_MIN / a) return 0;
    } else {
        if (b > 0 && a < LLONG_MIN / b) return 0;
        if (b < 0 && a < LLONG_MAX / b) return 0;
    }

    *result = a * b;
    return 1;
}

int main(void)
{
    int a[MAX_N];
    int c[MAX_N];
    int n;
    int k;
    long long product = 1;
    int has_nonzero = 0;

    printf("Введіть розмір масиву (1..%d): ", MAX_N);

    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_N) {
        printf("Помилка: некоректний розмір масиву.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    printf("Заданий масив A: ");
    print_array(a, n);

    printf("Введіть ціле число k (k < 10, k != 0): ");

    if (scanf("%d", &k) != 1 || k == 0 || k >= 10 || k <= -10) {
        printf("Помилка: некоректне значення k.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        c[i] = (int)((long long)a[i] % (long long)k);

        if (c[i] != 0) {
            long long next_product;

            if (!checked_multiply(product, c[i], &next_product)) {
                printf("Добуток виходить за межі типу long long.\n");
                return 1;
            }

            product = next_product;
            has_nonzero = 1;
        }
    }

    printf("Масив C (остачі): ");
    print_array(c, n);

    if (has_nonzero) {
        printf("Добуток ненульових елементів C: %lld\n", product);
    } else {
        printf("Ненульових елементів у масиві C немає.\n");
    }

    return 0;
}