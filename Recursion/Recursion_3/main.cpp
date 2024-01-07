#include <stdio.h>

int fact(int n)
{
    if(n > 0)
        return n * fact(n - 1);
    else
        return 1;
}

int main(int argc, char** argv)
{
    int n, total;
    printf("Enter an integer\n");
    scanf("%d", &n);
    total = fact(n);
    printf("%d", total);
    return 0;
}
