#include <stdio.h>

int N;
int arr[10];
// 1 <= N <= 10

void dfs(int depth, int end)
{
    int sum;
    int k;

    if (depth == N) // dice action == N
    {
        sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        printf("sum = %d", sum);
        if (end)
            printf("\n");
        else
            printf(", ");
        return;
    }
    for (int i = 1; i <= 6; i++) // dice number
    {
        k = 0;
        if (i + 1 == 7)
            k = 1;
        arr[depth] = i;
        dfs(depth + 1, k); // next dice
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    N = n;
    dfs(0, 0);
}