#include <stdio.h>

int power(int n)
{
    --n;
    if(n >= 0)
        return 2 * power(n);
    else
        return 1;
}
int main(int argc, char** argv)
{
    static int n;
    int total;
    printf("Enter the power of 2 to be calculated \n");
    scanf("%d",&n);
    total = power(n);
    printf("%d\n", total);
    return 0;
}
