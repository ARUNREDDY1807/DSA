#include <stdio.h>

#define MAX_N 100000

int check_gifts(int n, int age, int prices [])
{
    int i, j;
    int sum;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            sum = prices[i] + prices[j];
            if (sum == age * 100) {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int prices, n, age, i;
    scanf("%d", &age);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    if (check_gifts(n, age, prices)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
