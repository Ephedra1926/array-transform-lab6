#include <stdio.h>

#define N 12

void print_array(const int a[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
        printf("%5d", a[i]);   
    printf(" ]\n");
}

int main(void)
{
    int a[N] = {12, 25, 7, 40, 13, 8, 33, 5, 18, 9, 21, 30};
    int c[N];
    int k;

    printf("Заданий масив A: ");
    print_array(a, N);

    printf("Введіть ціле число k (k < 10): ");
    if (scanf("%d", &k) != 1 || k >= 10) {
        printf("Помилка: некоректне значення k\n");
        return 1;
    }

    if (k == 0) {
        printf("Помилка: ділення на нуль неможливе.\n");
        printf("Масив C не може бути утворений.\n");
        return 1;
    }

    for (int i = 0; i < N; i++)
        c[i] = (int)((long long)a[i] % (long long)k);

    printf("Масив C (остачі): ");
    print_array(c, N);

    long long product = 1;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (c[i] != 0) {
            product *= c[i];
            count++;
        }
    }

    if (count > 0)
        printf("Добуток ненульових елементів C: %lld\n", product);
    else
        printf("Ненульових елементів у масиві C немає\n");

    return 0;
}