#include <stdio.h>
void multi(int i, int j)
{
    if (j == 0)
    {
        return;
    }
    multi(i, j - 1);
    printf("%d*%d=%d\t", i, j, i * j);
}

int main()
{
    for (int i = 1; i <= 9; ++i)
    {
        multi(i, 9);
        printf("\n");
    }
    return 0;
}
