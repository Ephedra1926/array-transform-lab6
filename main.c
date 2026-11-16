
#include <stdio.h>
#include <limits.h>

#define MAX_N 100

int checked_multiply(long long a, long long b, long long *result) {
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

int main(void) {
    int n, k;
    int A[MAX_N], C[MAX_N];
    long long product = 1;
    int has_nonzero = 0;

    printf("Enter array size (1-%d): ", MAX_N);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_N) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d integer elements:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &A[i]) != 1) {
            printf("Invalid array element.\n");
            return 1;
        }
    }

    printf("Enter integer k (non-zero, less than 10): ");
    if (scanf("%d", &k) != 1 || k == 0 || k >= 10 || k <= -10) {
        printf("Invalid k. It must be non-zero and have absolute value less than 10.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        C[i] = A[i] % k;

        if (C[i] != 0) {
            long long new_product;

            if (!checked_multiply(product, C[i], &new_product)) {
                printf("Product is too large to calculate.\n");
                return 1;
            }

            product = new_product;
            has_nonzero = 1;
        }
    }

    printf("Original array A: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\nNew array C: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", C[i]);
    }

    if (has_nonzero) {
        printf("\nProduct of non-zero elements of C: %lld\n", product);
    } else {
        printf("\nThere are no non-zero elements in C.\n");
    }

    return 0;
}
