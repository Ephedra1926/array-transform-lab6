#include <stdio.h>

#define N 12

void print_array(const int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(void)
{
    int a[N] = {12, 25, 7, 40, 13, 8, 33, 5, 18, 9, 21, 30};
    int c[N];
    int k;

    printf("Заданий масив A: ");
    print_array(a, N);

    k = 0;

    printf("Перевірка особливого випадку: k = %d\n", k);

    if (k == 0) {
        printf("Помилка: ділення на нуль неможливе.\n");
        printf("Масив C не може бути утворений.\n");
        return 1;
    }

    for (int i = 0; i < N; i++)
        c[i] = a[i] % k;

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