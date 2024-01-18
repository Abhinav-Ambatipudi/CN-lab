#include<stdio.h>

int v[10], r = 0;

void rec(int a[10][10], int n, int s, int e, int sum)
{
    int i, t;
    if (s == e)
    {
        v[r] = sum;
        r = r + 1;
        return;
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (a[s][i] != 0)
            {
                sum = sum + a[s][i];
                t = a[s][i];
                printf("%d \t %d \n", sum, i);
                rec(a, n, i, e, sum);
                sum = sum - t;
            }
        }
    }
}

int main()
{
    int a[10][10], i, j, s, e, n, sum = 0;
    printf("enter the no of nodes:");
    scanf("%d", &n);
    printf("enter the values:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("enter the starting node:");
    scanf("%d", &s);
    printf("enter end node:");
    scanf("%d", &e);
    rec(a, n, s, e, sum);

    // Corrected this part
    int min = v[0];
    for (i = 0; i < r; i++)
    {
        if (min > v[i])
            min = v[i];
    }
    printf("shortest path:%d \n ", min);

    return 0;
}