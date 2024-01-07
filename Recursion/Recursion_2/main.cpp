#include <stdio.h>

int sum(int n)
{
    if(n > 0)
        return n + sum(n - 1);
    else
        return 0;
}

int main(int argc, char** argv)
{
    int n, total;
    printf("Enter an integer\n");
    scanf("%d", &n);
    total = sum(n);
    printf("%d", total);
    return 0;
}
