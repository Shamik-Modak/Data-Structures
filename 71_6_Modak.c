#include <stdio.h>

int decToBin(int x) {
    if (x == 0)
        return 0;
    else
        return (x % 2) + 10 * decToBin(x / 2);
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    printf("Binary = %d", decToBin(n));
    return 0;
}
